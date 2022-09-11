// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>

#include "GameState.hpp"
#include "Functions.hpp"
#include "Languages.hpp"



struct TerminalSize {
	unsigned int x;
	unsigned int y;
};

struct Entry {
	std::string text;
	void(*next_ptr)();
};



#ifdef WIN32
struct Border {
	const char* horizontal = "*";
	const char* vertical = "*";
	const char* top_left = "*";
	const char* top_right = "*";
	const char* bottom_left = "*";
	const char* bottom_right = "*";

	const char* horizontal_connector_down = "*";
	const char* horizontal_connector_up = "*";

	const char* vertical_connector_right = "*";
	const char* vertical_connector_left = "*";

	const char* connector = "*";
} border;

#include <windows.h>
TerminalSize getTerminalSize() {
	struct TerminalSize terminal;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	terminal.x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	terminal.y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return terminal;
};

#else
struct Border {
	const char* horizontal = "═";
	const char* vertical = "║";
	const char* top_left = "╔";
	const char* top_right = "╗";
	const char* bottom_left = "╚";
	const char* bottom_right = "╝";

	const char* horizontal_connector_down = "╦";
	const char* horizontal_connector_up = "╩";

	const char* vertical_connector_right = "╠";
	const char* vertical_connector_left = "╣";

	const char* connector = "╬";
} border;

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
TerminalSize getTerminalSize() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	struct TerminalSize terminal;
	terminal.y = w.ws_row;
	terminal.x = w.ws_col;
	return terminal;
};
#endif




template<const unsigned int rows, const unsigned int columns>
std::string Functions::box(const std::string title, const std::string (&entries)[rows][columns], const unsigned int width, unsigned int height) {
	// String to be returned
	std::string box;

	// String representing different row types
	std::string topBorder = border.top_left;
	std::string bottomBorder = border.bottom_left;
	std::string emptyRow = border.vertical;
	std::string borderRow = border.vertical_connector_right;
	struct TitleRow {
		std::string row = border.vertical;
		unsigned int horizontalOffset;
	} titleRow;
	struct TextRow {
		std::string row = border.vertical;
		unsigned int verticalOffset;
		unsigned int horizontalOffset[columns];
		unsigned int verticalPadding;
		unsigned int horizontalPadding[columns];
	} textRow[rows];


	if(title != std::string()) {
		height -= 2;

		titleRow.horizontalOffset = (width - title.length()) / 2;

		for(int i = 0; i < width - 2; i++) {
			if(i >= titleRow.horizontalOffset && i < titleRow.horizontalOffset + title.length()) {
				titleRow.row += title[i - titleRow.horizontalOffset];
			}
			else {
				titleRow.row += ' ';
			};
		};

		titleRow.row += border.vertical;
		titleRow.row += '\n';
	};

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
			topBorder += border.horizontal;
			bottomBorder += border.horizontal;
			emptyRow += ' ';
			borderRow += border.horizontal;

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
			topBorder += border.horizontal_connector_down;
			bottomBorder += border.horizontal_connector_up;
			emptyRow += border.vertical;
			borderRow += border.connector;
			for(int j = 0; j < rows; j++) {
				textRow[j].row += border.vertical;
			};
		};
	};

	// Finish each row and add \n
	topBorder += border.top_right;
	topBorder += '\n';

	bottomBorder += border.bottom_right;
	bottomBorder += '\n';

	emptyRow += border.vertical;
	emptyRow += '\n';

	borderRow += border.vertical_connector_left;
	borderRow += '\n';

	for(int i = 0; i < rows; i++) {
		textRow[i].row += border.vertical;
		textRow[i].row += '\n';
	};

	// Where to put vertical connectors
	unsigned int rowStep = (height - 2) / rows;

	// Entry vertical padding and offset
	for(int i = 0; i < rows; i++) {
		textRow[i].verticalPadding = (rowStep - 1) / 2;
		textRow[i].verticalOffset = rowStep * i + textRow[i].verticalPadding;
	};


	// Start concatenating to get final string
	box = topBorder;

	if(title != std::string()) {
		box += titleRow.row;
		box += borderRow;
	};

	// Add all rows to fill height
	// -2 for top and bottom, -1 for console to write command, -1 for status message ¯\_(ツ)_/¯
	for(int i = 0; i < height - 4; i++) {
		// Not adding a border/connector?
		if(((i + 1) % rowStep) || i + rowStep > height - 2) {
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


std::string Functions::textBox(const std::string title, std::string text, const unsigned int width, unsigned int height) {
	// String to be returned
	std::string box;

	// String representing different row types
	std::string topBorder = border.top_left;
	std::string bottomBorder = border.bottom_left;
	std::string emptyRow = border.vertical;
	std::string borderRow = border.vertical_connector_right;
	struct TitleRow {
		std::string row = border.vertical;
		unsigned int horizontalOffset;
	} titleRow;

	// Setup title if we have a title
	if(title != std::string()) {
		height -= 2;

		titleRow.horizontalOffset = (width - title.length()) / 2;

		for(int i = 0; i < width - 2; i++) {
			if(i >= titleRow.horizontalOffset && i < titleRow.horizontalOffset + title.length()) {
				titleRow.row += title[i - titleRow.horizontalOffset];
			}
			else {
				titleRow.row += ' ';
			};
		};

		titleRow.row += border.vertical;
		titleRow.row += '\n';
	};


	for(int i = 0; i < width - 2; i++) {
		topBorder += border.horizontal;
		emptyRow += ' ';
		bottomBorder += border.horizontal;
		borderRow += border.horizontal;
	};

	topBorder += border.top_right;
	topBorder += '\n';

	bottomBorder += border.bottom_right;
	bottomBorder += '\n';

	emptyRow += border.vertical;
	emptyRow += '\n';

	borderRow += border.vertical_connector_left;
	borderRow += '\n';


	box += topBorder;

	if(title != std::string()) {
		box += titleRow.row;
		box += borderRow;
	};

	for(int i = 0; i < height - 2; i++) {
		if(i < height * .1 || i > height * .9) {
			box += emptyRow;
		}
		else {
			// If we have a NL in the text, let's remove it
			if(text[0] == '\n') {
				text.erase(0, 1);
			};
			// Needed to see if we encountered a NL in the current line, so that we can print spaces until it ends
			bool nl = false;
			box += border.vertical;
			for(int j = 0; j < width - 2; j++) {
				if(j < width * .1 || j > width * .9 || !text.length() || nl) {
					box += ' ';
				}
				else {
					if(text[0] == '\n') {
						nl = true;
						box += ' ';
					}
					else {
						box += text[0];
						text.erase(0, 1);
					};
				};
			};
			box += border.vertical;
			box += '\n';
		};
	};

	box += bottomBorder;

	return box;
};


template<const unsigned int rows, const unsigned int columns>
std::string Functions::fullScreenBox(const std::string title, const std::string (&entries)[rows][columns]) {

	TerminalSize terminal = getTerminalSize();
	return Functions::box<rows, columns>(title, entries, terminal.x, terminal.y);
};


std::string Functions::fullScreenTextBox(const std::string title, std::string text) {

	TerminalSize terminal = getTerminalSize();
	return Functions::textBox(title, text, terminal.x, terminal.y);
};



template<const unsigned int length>
Entry entryFromString(const Entry (&entries)[length], std::string search) {
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



template<const unsigned int rows, unsigned int columns>
void drawBoxAndSetNextFunctionOnUserInput(std::string title, const struct Entry (&entries)[rows][columns], std::string statusMessage, void(*caller)()) {
	// Strings to display
	std::string strings[rows][columns];
	// 1D array to search for input
	struct Entry entriesArray[rows * columns];

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			strings[i][j] = entries[i][j].text;
			entriesArray[i * columns + j] = entries[i][j];
		};
	};

	while(GameState::gameFunction == caller) {
		std::cout << Functions::fullScreenBox<rows, columns>(title, strings) << statusMessage << std::endl;

		std::string command;
		std::getline(std::cin, command);

		try {
			const struct Entry action = entryFromString<rows * columns>(entriesArray, command);
			statusMessage = action.text;
			if(action.next_ptr != NULL) {
				GameState::gameFunction = action.next_ptr;
			};
		} catch(const std::exception& e) {
			statusMessage = "That's not an option";
		};
	};
	return;
};


template<const unsigned int rows, unsigned int columns>
void drawTextBoxAndSetNextFunctionOnUserInput(std::string title, const std::string text, const struct Entry (&entries)[rows][columns], std::string statusMessage, void(*caller)()) {
	// 1D array to search for input
	struct Entry entriesArray[rows * columns];

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			entriesArray[i * columns + j] = entries[i][j];
		};
	};

	while(GameState::gameFunction == caller) {
		std::cout << Functions::fullScreenTextBox(title, text) << statusMessage << std::endl;

		std::string command;
		std::getline(std::cin, command);

		try {
			const struct Entry action = entryFromString<rows * columns>(entriesArray, command);
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
	const struct Entry entries[rows][columns] = {
		{ Languages::strings[GameState::settings.language][Languages::STRING_English], NULL },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Italian], NULL },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Back], Functions::settings }
	};

	// Strings to display
	std::string strings[rows][columns];
	// 1D array to search for input
	struct Entry entriesArray[rows * columns];

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			strings[i][j] = entries[i][j].text;
			entriesArray[i * columns + j] = entries[i][j];
		};
	};

	std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Select_A_Language];

	while(GameState::gameFunction == setLanguage) {
		std::cout << Functions::fullScreenBox<rows, columns>("Language", strings) << statusMessage << std::endl;

		std::string command;
		std::cin >> command;

		try {
			const struct Entry selectedLanguage = entryFromString<rows * columns>(entriesArray, command);

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
	const struct Entry entries[rows][columns] = {
		{ Languages::strings[GameState::settings.language][Languages::STRING_Language], setLanguage },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Reset_settings], resetSettings },
		{ Languages::strings[GameState::settings.language][Languages::STRING_Back], GameState::prevGameFunction }
	};

	std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Select_An_Option];

	drawBoxAndSetNextFunctionOnUserInput<rows, columns>("Settings", entries, statusMessage, Functions::settings);

	GameState::writeSettings();

	return;
};


void Functions::quit() {
	std::cout << "Bye Bye!" << std::endl;
	exit(0);
	return;
};


void Functions::mainMenu() {
	// Entries available to select
	const unsigned int rows = 3;
	const unsigned int columns = 1;
	const struct Entry entries[rows][columns] = {
		{{ Languages::strings[GameState::settings.language][Languages::STRING_Start], Functions::introduction}},
		{{ Languages::strings[GameState::settings.language][Languages::STRING_Settings], Functions::settings }},
		{{ Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	std::string statusMessage = Languages::status[GameState::settings.language][Languages::STATUS_Enter_A_Command];

	drawBoxAndSetNextFunctionOnUserInput<rows, columns>("Main Menu", entries, statusMessage, Functions::mainMenu);
	GameState::prevGameFunction = Functions::mainMenu;
	return;
};

void Functions::introduction() {
	fullScreenTextBox("Prologo", Languages::story[GameState::settings.language][Languages::STORY_Intro]);
	GameState::gameFunction = Functions::Phase1::start;
};

bool Functions::chance(){
	return rand()%2;
};


void Functions::Phase1::start() {
	const unsigned int rows = 2;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Phase1::west}, { "Nord", Functions::Phase1::north}, { "Est", Functions::Phase1::east}, { "Sud", Functions::Phase1::south}},
		{{ "Guardati attorno", NULL}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Bivio", Languages::story[GameState::settings.language][Languages::STORY_Phase1_Start], entries, "Write a command", Functions::Phase1::start);

	GameState::prevGameFunction = Functions::introduction;
	return;
};

void Functions::Phase1::west() {
	const unsigned int rows = 2;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase2::W::obstacle}, { "Nord", Functions::Phase2::W::obstacle}, { "Est", Functions::Phase1::start}, { "Sud", Functions::Phase2::W::obstacle}},
		{{ "Guardati attorno", Functions::Phase2::W::lookAround}, { "Arrampicati", Functions::Phase2::W::climb}, {"Ficus", NULL}, {"Palma", NULL}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Foresta", Languages::story[GameState::settings.language][Languages::STORY_Phase1_West], entries, "Write a command", Functions::Phase1::west);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase1::north() {
	const unsigned int rows = 2;
	const unsigned int columns = 4;

	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase2::N::obstacle}, { "Nord", NULL}, { "Est", Functions::Phase2::N::obstacle}, { "Sud", Functions::Phase1::start}},
		{{ "Guardati attorno", Functions::Phase2::N::lookAround}, { "Arrampicati", Functions::Phase2::N::climb}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Piazza", Languages::story[GameState::settings.language][Languages::STORY_Phase1_North], entries, "Write a command", Functions::Phase1::north);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase1::east() {
	const unsigned int rows = 2;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase1::start}, { "Nord", Functions::Phase2::E::obstacle}, { "Est", Functions::Phase2::E::drink}, { "Sud", Functions::Phase2::E::obstacle}},
		{{ "Guardati attorno", Functions::Phase2::E::lookAround}, { "Bevi", Functions::Phase2::E::drink}, {"Barca", Functions::Phase2::E::boat}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Fiume", Languages::story[GameState::settings.language][Languages::STORY_Phase1_East], entries, "Write a command", Functions::Phase1::east);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase1::south() {
	const unsigned int rows = 2;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase1::west}, { "Nord", Functions::Phase1::north}, { "Est", Functions::Phase1::east}, { "Sud", Functions::Phase1::south}},
		{{ "Guardati attorno", NULL}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Bivio", Languages::story[GameState::settings.language][Languages::STORY_Phase1_South], entries, "Write a command", Functions::Phase1::east);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase1::lookAround() {
	const unsigned int rows = 2;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase1::west}, { "Nord", Functions::Phase1::north}, { "Est", Functions::Phase1::east}, { "Sud", Functions::Phase1::south}},
		{{ "Guardati attorno", NULL}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Bivio", Languages::story[GameState::settings.language][Languages::STORY_Phase1_LookAround], entries, "Write a command", Functions::Phase1::lookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::W::obstacle() {
	const unsigned int rows = 2;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase2::W::obstacle}, { "Nord", Functions::Phase2::W::obstacle}, { "Est", Functions::Phase1::start}, { "Sud", Functions::Phase2::W::obstacle}},
		{{ "Guardati attorno", Functions::Phase2::W::lookAround}, { "Arrampicati", Functions::Phase2::W::climb}, {"Ficus", NULL}, {"Palma", NULL}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Foresta", Languages::story[GameState::settings.language][Languages::STORY_Phase2W_Obstacle], entries, "Write a command", Functions::Phase2::W::obstacle);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::W::lookAround() {
	const unsigned int rows = 2;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase2::W::obstacle}, { "Nord", Functions::Phase2::W::obstacle}, { "Est", Functions::Phase1::start}, { "Sud", Functions::Phase2::W::obstacle}},
		{{ "Guardati attorno", Functions::Phase2::W::lookAround}, { "Arrampicati", Functions::Phase2::W::climb}, {"Ficus", NULL}, {"Palma", NULL}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Foresta", Languages::story[GameState::settings.language][Languages::STORY_Phase2W_LookAround], entries, "Write a command", Functions::Phase2::W::lookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::W::climb() {
	const unsigned int rows = 2;
	const unsigned int columns = 3;
	const struct Entry entries[rows][columns] {
		{{"1", Functions::Phase2::W::ficus}, {"2", Functions::Phase2::W::palm}},
		{{"Ficus", Functions::Phase2::W::ficus}, {"Palma", Functions::Phase2::W::palm}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Foresta", Languages::story[GameState::settings.language][Languages::STORY_Phase2W_Climb], entries, "Write a command", Functions::Phase2::W::climb);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::W::ficus() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase3::W::ficusEat}, {"Prosegui", Functions::Phase3::W::ficusProceed}, {"Guardati attorno", Functions::Phase3::W::ficusLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Ficus", Languages::story[GameState::settings.language][Languages::STORY_Intro], entries, "Write a command", Functions::Phase2::W::ficus);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::W::palm() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase3::W::palmEat}, {"Prosegui", Functions::Phase3::W::palmProceed}, {"Guardati attorno", Functions::Phase3::W::palmLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Palma", Languages::story[GameState::settings.language][Languages::STORY_Intro], entries, "Write a command", Functions::Phase2::W::palm);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::N::obstacle() {
	const unsigned int rows = 2;
	const unsigned int columns = 4;

	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase2::N::obstacle}, { "Nord", Functions::Phase3::N::jaguar}, { "Est", Functions::Phase2::N::obstacle}, { "Sud", Functions::Phase1::start}},
		{{ "Guardati attorno", Functions::Phase2::N::lookAround}, { "Arrampicati", Functions::Phase3::N::hornet}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Piazza", Languages::story[GameState::settings.language][Languages::STORY_Phase2N_Obstacle], entries, "Write a command", Functions::Phase2::N::obstacle);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::N::lookAround() {
	const unsigned int rows = 2;
	const unsigned int columns = 4;

	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase2::N::obstacle}, { "Nord", Functions::Phase3::N::jaguar}, { "Est", Functions::Phase2::N::obstacle}, { "Sud", Functions::Phase1::start}},
		{{ "Guardati attorno", Functions::Phase2::N::lookAround}, { "Arrampicati", Functions::Phase3::N::hornet}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Piazza", Languages::story[GameState::settings.language][Languages::STORY_Phase2N_LookAround], entries, "Write a command", Functions::Phase2::N::lookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::E::obstacle() {
	const unsigned int rows = 2;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase1::start}, { "Nord", Functions::Phase2::E::obstacle}, { "Est", Functions::Phase2::E::drink}, { "Sud", Functions::Phase2::E::obstacle}},
		{{ "Guardati attorno", Functions::Phase2::E::lookAround}, { "Bevi", Functions::Phase2::E::drink}, {"Barca", Functions::Phase2::E::boat}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Fiume", Languages::story[GameState::settings.language][Languages::STORY_Phase2E_Obstacle], entries, "Write a command", Functions::Phase2::E::obstacle);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::E::lookAround() {
	const unsigned int rows = 2;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{ "Ovest", Functions::Phase1::start}, { "Nord", Functions::Phase2::E::obstacle}, { "Est", Functions::Phase2::E::drink}, { "Sud", Functions::Phase2::E::obstacle}},
		{{ "Guardati attorno", Functions::Phase2::E::lookAround}, { "Bevi", Functions::Phase2::E::drink}, {"Barca", Functions::Phase2::E::boat}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Fiume", Languages::story[GameState::settings.language][Languages::STORY_Phase2E_LookAround], entries, "Write a command", Functions::Phase2::E::lookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase2::E::drink() {
	GameState::gameOver = false;
}

void Functions::Phase2::E::boat() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Combatti", Functions::Phase3::E::fight}, {"Fai amicizia", Functions::Phase3::E::befriend}, {"Guardati attorno", Functions::Phase4::W::run}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Turisti", Languages::story[GameState::settings.language][Languages::STORY_Phase2E_Boat], entries, "Write a command", Functions::Phase2::E::boat);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::W::ficusEat() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Combatti", Functions::Phase4::W::fight}, {"Fai amicizia", Functions::Phase4::W::befriend}, {"Scappa", Functions::Phase4::W::run}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Cacciatore", Languages::story[GameState::settings.language][Languages::STORY_Phase3W_FicusEat], entries, "Write a command", Functions::Phase3::W::ficusEat);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::W::ficusProceed() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Combatti", Functions::Phase4::W::fight}, {"Fai amicizia", Functions::Phase4::W::befriend}, {"Scappa", Phase4::W::run}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};
	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Cacciatore", Languages::story[GameState::settings.language][Languages::STORY_Phase3W_FicusProceed], entries, "Write a command", Functions::Phase3::W::ficusProceed);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::W::ficusLookAround() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase3::W::ficusEat}, {"Prosegui", Functions::Phase3::W::ficusProceed}, {"Guardati attorno", Functions::Phase3::W::ficusLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Ficus", Languages::story[GameState::settings.language][Languages::STORY_Phase3W_FicusLookAround], entries, "Write a command", Functions::Phase3::W::ficusLookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::W::palmEat() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	if(rand()%2){
		const struct Entry entries[rows][columns] {
			{{"Combatti", Functions::Phase4::W::fight}, {"Fai amicizia", Functions::Phase4::W::befriend}, {"Scappa", Functions::Phase4::W::run}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
		};
		drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Cacciatore", Languages::story[GameState::settings.language][Languages::STORY_Phase3W_PalmEat], entries, "Write a command", Functions::Phase3::W::palmEat);
	}
	else{
		GameState::gameOver = true;
	}
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::W::palmProceed() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Combatti", Functions::Phase4::W::fight}, {"Fai amicizia", Functions::Phase4::W::befriend}, {"Scappa", Functions::Phase4::W::run}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Cacciatore", Languages::story[GameState::settings.language][Languages::STORY_Phase3W_PalmProceed], entries, "Write a command", Functions::Phase3::W::palmProceed);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::W::palmLookAround() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase3::W::palmEat}, {"Prosegui", Functions::Phase3::W::palmProceed}, {"Guardati attorno", Functions::Phase3::W::palmLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Palma", Languages::story[GameState::settings.language][Languages::STORY_Phase3W_PalmLookAround], entries, "Write a command", Functions::Phase3::W::palmLookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::N::jaguar() {
	const unsigned int rows = 1;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{"Combatti", Functions::Phase3::N::jaguarFight}, {"Scappa", Functions::Phase3::N::jaguarRun}, {"Arrampicati", Functions::Phase4::N::village}, {"Guardati attorno", Functions::Phase3::N::jaguarLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Giaguaro", Languages::story[GameState::settings.language][Languages::STORY_Phase3N_Jaguar], entries, "Write a command", Functions::Phase3::N::jaguar);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::N::jaguarFight() {
	GameState::gameOver = true;
};

void Functions::Phase3::N::jaguarRun() {
	Gamestate::gameover = true;
};

void Functions::Phase3::N::jaguarClimb() {
	const unsigned int rows = 1;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{"Entra", Functions::Phase4::N::villageEnter}, {"Ignora", Functions::Phase4::N::villageIgnore}, {"Guardati attorno", Functions::Phase3::N::jaguarLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Villaggio", Languages::story[GameState::settings.language][Languages::STORY_Phase3N_JaguarClimb], entries, "Write a command", Functions::Phase3::N::jaguarClimb);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::N::jaguarLookAround() {
	const unsigned int rows = 1;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{"Combatti", Functions::Phase3::N::jaguarFight}, {"Scappa", Functions::Phase3::N::jaguarRun}, {"Arrampicati", Functions::Phase3::N::jaguarClimb}, {"Guardati attorno", Functions::Phase3::N::jaguarLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Giaguaro", Languages::story[GameState::settings.language][Languages::STORY_Phase3N_JaguarLookAround], entries, "Write a command", Functions::Phase3::N::jaguarLookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};


void Functions::Phase3::N::hornet() {
	const unsigned int rows = 1;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase3::N::hornetEat}, {"Procedi", Functions::Phase3::N::hornetProceed}, {"Guardati attorno", Functions::Phase3::N::hornetLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Nido di calabroni", Languages::story[GameState::settings.language][Languages::STORY_Phase3N_Hornet], entries, "Write a command", Functions::Phase3::N::hornet);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase3::N::hornetEat() {
	if(rand()%2){
		const unsigned int rows = 1;
		const unsigned int columns = 5;
		const struct Entry entries[rows][columns] {
			{{"Entra", Functions::Phase4::N::villageEnter}, {"Ignora", Functions::Phase4::N::villageIgnore}, {"Guardati attorno", Functions::Phase4::N::villageLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
		};

		drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Nido di calabroni", Languages::story[GameState::settings.language][Languages::STORY_Phase3N_HornetEat], entries, "Write a command", Functions::Phase3::N::hornetEat);
		GameState::prevGameFunction = Functions::Phase1::start;
		return;
	}
	else{
		GameState::gameOver = true;
	}
};

void Functions::Phase3::N::hornetProceed() {
	if(rand()%2){
		const unsigned int rows = 1;
		const unsigned int columns = 5;
		const struct Entry entries[rows][columns] {
			{{"Entra", Functions::Phase4::N::villageEnter}, {"Ignora", Functions::Phase4::N::villageIgnore}, {"Guardati attorno", Functions::Phase4::N::villageLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
		};

		drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Nido di calabroni", Languages::story[GameState::settings.language][Languages::STORY_Phase3N_HornetProceed], entries, "Write a command", Functions::Phase3::N::hornetProceed);
		GameState::prevGameFunction = Functions::Phase1::start;
		return;
	}
	else{
		GameState::gameOver = true;
	}
};

void Functions::Phase3::N::hornetLookAround() {
	const unsigned int rows = 1;
	const unsigned int columns = 5;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase3::N::hornetEat}, {"Procedi", Functions::Phase3::N::hornetProceed}, {"Guardati attorno", Functions::Phase3::N::hornetLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Nido di calabroni", Languages::story[GameState::settings.language][Languages::STORY_Phase3N_HornetLookAround], entries, "Write a command", Functions::Phase3::N::hornetLookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase4::W::fight() {
	GameState::gameOver = true;
};

void Functions::Phase4::W::befriend() {
	GameState::gameOver = true;
};

void Functions::Phase4::W::run() {
	GameState::gameOver = true;
};

void Functions::Phase4::N::villageEnter() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase4::N::fruitEat}, {"Ignora", Functions::Phase4::N::fruitIgnore}, {"Guardati attorno", Functions::Phase4::N::villageLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Villaggio", Languages::story[GameState::settings.language][Languages::STORY_Phase4N_VillageEnter], entries, "Write a command", Functions::Phase4::N::villageEnter);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase4::N::villageIgnore() {
	Gamestate::gameOver = true;
};

void Functions::Phase4::N::villageLookAround() {
	const unsigned int rows = 1;
	const unsigned int columns = 4;
	const struct Entry entries[rows][columns] {
		{{"Mangia", Functions::Phase5::N::fruitEat}, {"Ignora", Functions::Phase5::N::fruitIgnore}, {"Guardati attorno", Functions::Phase4::N::villageLookAround}, { Languages::strings[GameState::settings.language][Languages::STRING_Quit], Functions::quit }}
	};

	drawTextBoxAndSetNextFunctionOnUserInput<rows, columns>("Villaggio", Languages::story[GameState::settings.language][Languages::STORY_Phase4N_VillageLookAround], entries, "Write a command", Functions::Phase4::N::villageLookAround);
	GameState::prevGameFunction = Functions::Phase1::start;
	return;
};

void Functions::Phase5::N::fruitEat() {
	if(rand()%2){
		GameState::gameOver = true;
	}
	else{
		GameState::gameOver = true;
	}
};

void Functions::Phase5::N::fruitIgnore() {
	GameState::gameOver = true;
};