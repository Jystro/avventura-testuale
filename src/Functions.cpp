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
	unsigned int rowStep = (heigth - 1) / rows;

	// Entry vertical padding and offset
	for(int i = 0; i < rows; i++) {
		textRow[i].verticalPadding = (rowStep - 1) / 2;
		textRow[i].verticalOffset = rowStep * i + textRow[i].verticalPadding;
	};


	// Start concatenating to get final string
	box = topBorder;

	// Add all rows to fill height
	// -2 for top and bottom, -1 for console to write command ¯\_(ツ)_/¯
	for(int i = 0; i < heigth - 3; i++) {
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


void Functions::startMenu() {
	// Entries to display
	const struct Functions::Entry entries[2][2] = {
		{{ Languages::languages[GameState::language][Languages::STRING_START], NULL }, { Languages::languages[GameState::language][Languages::STRING_MENU], NULL }},
		{{ Languages::languages[GameState::language][Languages::STRING_QUIT], NULL }, { Languages::languages[GameState::language][Languages::STRING_SETTINGS], NULL }}
	};
	
	std::string strings[2][2];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			strings[i][j] = entries[i][j].text;
		}
	}

	// std::cout << __func__ << std::endl; Might be useful
	std::cout << Functions::box<2, 2>(strings, 50, 8) << std::endl;
	std::cout << Functions::fullScreenBox<2, 2>(strings);
	return;
};
