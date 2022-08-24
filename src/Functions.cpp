// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>

#include "GameState.hpp"
#include "Functions.hpp"
#include "Languages.hpp"

#ifdef WIN32
#include <windows.h>
Functions::TerminalSize Functions::getTerminalSize() {
	struct Functions::TerminalSize terminal;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	terminal.x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	terminal.y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return terminal;
};
#else
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
Functions::TerminalSize Functions::getTerminalSize() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	struct Functions::TerminalSize terminal;
	terminal.y = w.ws_row;
	terminal.x = w.ws_col;
	return terminal;
};
#endif


template<const unsigned int rows, const unsigned int columns>
std::string Functions::box(const std::string (&entries)[rows][columns], const unsigned int width, const unsigned int heigth) {
	// String to be returned
	std::string box;

	// String representing different row types
	std::string topBorder = Functions::border_top_left;
	std::string bottomBorder = Functions::border_bottom_left;
	std::string emptyRow = Functions::border_vertical;
	std::string borderRow = Functions::border_vertical_connector_right;
	struct TextRow {
		std::string row = Functions::border_vertical;
		unsigned int verticalOffset;
		unsigned int horizontalOffset[columns];
		unsigned int verticalPadding;
		unsigned int horizontalPadding[columns];
	} textRow[rows];


	// Where to put horizontal connectors
	unsigned int columnStep = width / columns;

	// Entry horizontal padding and offset
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			textRow[i].horizontalPadding[j] = (columnStep - entries[i][j].length()) / 2;
			textRow[i].horizontalOffset[j] = columnStep * j + textRow[i].horizontalPadding[j];
		};
	};

	// Create all types of rows
	for(int i = 0; i < width - 2; i++) {
		// Check if we're not adding a connector
		if(((i + 1) % columnStep) || i + columnStep > width) {
			topBorder += Functions::border_horizontal;
			bottomBorder += Functions::border_horizontal;
			emptyRow += ' ';
			borderRow += Functions::border_horizontal;

			for(int j = 0; j < rows; j++) {
				// Check if we're inserting a letter or blank space
				bool blank = true;
				for(int k = 0; k < columns; k++) {
					if(i >= textRow[j].horizontalOffset[k] && i < textRow[j].horizontalOffset[k] + entries[j][k].length()) {
						textRow[j].row += entries[j][k][i - textRow[j].horizontalOffset[k]];
						blank = false;
					};
				};
				if(blank) {
					textRow[j].row += ' ';
				};
			};
		}
		// Otherwise add a connector
		else {
			topBorder += Functions::border_horizontal_connector_down;
			bottomBorder += Functions::border_horizontal_connector_up;
			emptyRow += Functions::border_vertical;
			borderRow += Functions::border_connector;
			for(int j = 0; j < rows; j++) {
				textRow[j].row += Functions::border_vertical;
			};
		};
	};

	// Finish each row and add \n
	topBorder += Functions::border_top_right;
	topBorder += '\n';

	bottomBorder += Functions::border_bottom_right;
	bottomBorder += '\n';

	emptyRow += Functions::border_vertical;
	emptyRow += '\n';

	borderRow += Functions::border_vertical_connector_left;
	borderRow += '\n';

	for(int i = 0; i < rows; i++) {
		textRow[i].row += Functions::border_vertical;
		textRow[i].row += '\n';
	};

	// Where to put vertical connectors
	unsigned int rowStep = (heigth - 2) / rows;

	// Entry vertical padding and offset
	for(int i = 0; i < rows; i++) {
		textRow[i].verticalPadding = (rowStep - 1) / 2;
		textRow[i].verticalOffset = rowStep * i + textRow[i].verticalPadding;
	};


	// Start concatenating to get final string
	box = topBorder;

	// Add all rows to fill height
	// -2 for top and bottom, -1 for console to write command, -1 for status message ¯\_(ツ)_/¯
	for(int i = 0; i < heigth - 4; i++) {
		// Not adding a border/connector?
		if(((i + 1) % rowStep) || i + rowStep > heigth - 2) {
			bool blank = true;
			for(int j = 0; j < rows; j++) {
				// Check if adding a text row
				if(i == textRow[j].verticalOffset) {
					box += textRow[j].row;
					blank = false;
				};
			};
			if(blank) {
				box += emptyRow;
			};
		}
		else {
			box += borderRow;
		};
	};
	box += bottomBorder;

	return box;
};


template<const unsigned int rows, const unsigned int columns>
std::string Functions::fullScreenBox(const std::string (&entries)[rows][columns]) {

	Functions::TerminalSize terminal = Functions::getTerminalSize();
	return Functions::box<rows, columns>(entries, terminal.x, terminal.y);
};



template<const unsigned int length>
Functions::Entry Functions::entryFromString(const Functions::Entry (&entries)[length], std::string search) {
	// Transform search string to lower case
	std::transform(search.begin(), search.end(), search.begin(), ::tolower);
	for(int i = 0; i < length; i++) {
		std::string lowercaseEntry = entries[i].text;
		// Transfor entry string to lower case
		std::transform(lowercaseEntry.begin(), lowercaseEntry.end(), lowercaseEntry.begin(), ::tolower);
		if(lowercaseEntry == search) {
			return entries[i];
		};
	};
	throw std::exception();
};



void Functions::quit() {
	std::cout << Languages::status[GameState::settings.language][Languages::STATUS_Bye] << std::endl;
	exit(0);
	return;
};

template<const unsigned int rows, unsigned int columns>
void nextFunctionOnUserInput(const struct Functions::Entry (&entries)[rows][columns], std::string statusMessage, void(*caller)()) {
	// Strings to display
	std::string strings[rows][columns];
	// 1D array to search for input
	struct Functions::Entry entriesArray[rows * columns];

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			strings[i][j] = entries[i][j].text;
			entriesArray[i * columns + j] = entries[i][j];
		};
	};

	while(GameState::gameFunction == caller) {
		std::cout << Functions::fullScreenBox<rows, columns>(strings) << statusMessage << std::endl;

		std::string command;
		std::getline(std::cin, command);

		try {
			const struct Functions::Entry action = Functions::entryFromString<rows * columns>(entriesArray, command);
			statusMessage = action.text;
			if(action.next_ptr != NULL) {
				GameState::gameFunction = action.next_ptr;
			};
		} catch(const std::exception& e) {
			std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Unavailable_Option];
		};
	};
	return;
};



void setLanguage() {
	// Entries available to select
	const unsigned int rows = 3;
	const unsigned int columns = 1;
	const struct Functions::Entry entries[rows][columns] = {
		{ Languages::strings[GameState::settings.language][Languages::STRING_English], NULL },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Italian], NULL },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Back], Functions::settings }
	};

	// Strings to display
	std::string strings[rows][columns];
	// 1D array to search for input
	struct Functions::Entry entriesArray[rows * columns];

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			strings[i][j] = entries[i][j].text;
			entriesArray[i * columns + j] = entries[i][j];
		};
	};

	std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Select_A_Language];

	while(GameState::gameFunction == setLanguage) {
		std::cout << Functions::fullScreenBox<rows, columns>(strings) << statusMessage << std::endl;

		std::string command;
		std::cin >> command;

		try {
			const struct Functions::Entry selectedLanguage = Functions::entryFromString<rows * columns>(entriesArray, command);

			if(selectedLanguage.next_ptr != NULL) {
				GameState::gameFunction = selectedLanguage.next_ptr;
			}
			else {
				statusMessage = selectedLanguage.text;

				for(int i = 0; i < rows * columns; i++) {
					if(entriesArray[i].text == selectedLanguage.text) {
						GameState::settings.language = static_cast<Languages::Language>(i);
						GameState::gameFunction = Functions::settings;
					};
				};
			};
		} catch(const std::exception& e) {
			std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Unavailable_Option];
		};
	};
	return;
};


void resetSettings() {
	GameState::resetSettings();

	GameState::gameFunction = Functions::settings;
	return;
};



void Functions::settings() {
	// Entries available to select
	const unsigned int rows = 3;
	const unsigned int columns = 1;
	const struct Functions::Entry entries[rows][columns] = {
		{ Languages::strings[GameState::settings.language][Languages::STRING_Language], setLanguage },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Reset_settings], resetSettings },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Back], GameState::prevGameFunction }
	};

	std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Select_An_Option];

	nextFunctionOnUserInput<rows, columns>(entries, statusMessage, Functions::settings);

	GameState::writeSettings();

	return;
};


void Functions::startMenu() {
	// Entries available to select
	const unsigned int rows = 3;
	const unsigned int columns = 1;
	const struct Functions::Entry entries[rows][columns] = {
		{{ Languages::strings[GameState::settings.language][Languages::STRING_Start], NULL }},
		{{ Languages::strings[GameState::settings.language][Languages::STRING_Settings], Functions::settings }},
		{{ Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Enter_A_Command];

	nextFunctionOnUserInput<rows, columns>(entries, statusMessage, Functions::startMenu);
	GameState::prevGameFunction = Functions::startMenu;
	return;
};
