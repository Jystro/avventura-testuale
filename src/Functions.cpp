#include <iostream>
#include <string>
#include "GameState.hpp"
#include "Functions.hpp"
#include "Languages.hpp"

#ifdef WIN32
#include <windows.h>
Functions::terminalSize Functions::getTerminalSize() {
	struct Functions::terminalSize terminal;
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
Functions::terminalSize Functions::getTerminalSize() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	struct Functions::terminalSize terminal;
	terminal.y = w.ws_row;
	terminal.x = w.ws_col;
	return terminal;
};
#endif


template<const unsigned int rows, const unsigned int columns>
std::string Functions::box(const struct Functions::entry (&entries)[rows][columns], const unsigned int width, const unsigned int heigth) {
	// String to be returned
	std::string box;

	// String representing different row types
	std::string topBorder = Functions::border_top_left;
	std::string bottomBorder = Functions::border_bottom_left;
	std::string emptyRow = Functions::border_vertical;
	std::string borderRow = Functions::border_vertical_connector_right;


	// Where to put horizontal connectors
	unsigned int columnStep = width / columns;

	// Create all types of rows
	for(int i = 0; i < width - 2; i++) {
		if(((i + 1) % columnStep) || i + columnStep > width) {
			topBorder += Functions::border_horizontal;
			bottomBorder += Functions::border_horizontal;
			emptyRow += ' ';
			borderRow += Functions::border_horizontal;
		}
		else {
			topBorder += Functions::border_horizontal_connector_down;
			bottomBorder += Functions::border_horizontal_connector_up;
			emptyRow += Functions::border_vertical;
			borderRow += Functions::border_connector;
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


	// Where to put vertical connectors
	unsigned int rowStep = (heigth - 1) / rows;

	// Start concatenating to get final string
	box = topBorder;

	// -2 for top and bottom, -1 for console to write command ¯\_(ツ)_/¯
	for(int i = 0; i < heigth - 3; i++) {
		if(((i + 1) % rowStep) || i + rowStep > heigth - 2) {
			box += emptyRow;
		}
		else {
			box += borderRow;
		};
	};
	box += bottomBorder;

	// Debugging purpose, remove later
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			std::cout << entries[i][j].text << ' ';
		};
		std::cout << std::endl;
	};


	return box;
};



template<const unsigned int rows, const unsigned int columns>
std::string Functions::fullScreenBox(const struct Functions::entry (&entries)[rows][columns]) {

	Functions::terminalSize terminal = Functions::getTerminalSize();
	return Functions::box<rows, columns>(entries, terminal.x, terminal.y);
};


void Functions::startMenu() {
	// Entries to display
	const struct Functions::entry entries[2][2] = {
		{{ Languages::languages[GameState::language][Languages::STRING_START], NULL }, {Languages::languages[GameState::language][Languages::STRING_MENU], NULL }},
		{{ Languages::languages[GameState::language][Languages::STRING_QUIT], NULL }, {Languages::languages[GameState::language][Languages::STRING_SETTINGS], NULL }}
	};

	// std::cout << __func__ << std::endl; Might be useful
	std::cout << Functions::box<2, 2>(entries, 80, 8) << std::endl;
	std::cout << Functions::fullScreenBox<2, 2>(entries);
	return;
};
