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
	terminal.y = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	terminal.x = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return terminal;
}
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
std::string Functions::fullScreenBox(const struct Functions::item (&entries)[rows][columns]) {
	std::string box;
	std::string topBorder = Functions::border_top_left;
	std::string bottomBorder = Functions::border_bottom_left;
	std::string emptyRow = Functions::border_vertical;

	Functions::terminalSize terminal = Functions::getTerminalSize();

	// first row of border
	for(int i = 0; i < terminal.x - 2; i++) {
		topBorder += Functions::border_horizontal;
		bottomBorder += Functions::border_horizontal;
		emptyRow += ' ';
	};
	topBorder += Functions::border_top_right;
	topBorder += '\n';

	bottomBorder += Functions::border_bottom_right;
	bottomBorder += '\n';

	emptyRow += Functions::border_vertical;
	emptyRow += '\n';

	box = topBorder;
	// -2 for top and bottom, -1 for console to write command ¯\_(ツ)_/¯
	for(int i = 0; i < terminal.y - 3; i++) {
		box += emptyRow;
	};
	box += bottomBorder;

	return box;
};



void Functions::startMenu() {
	// options to display
	const struct Functions::item options[2][1] = {
		{ Languages::languages[GameState::language][Languages::STRING_START], NULL },
		{ Languages::languages[GameState::language][Languages::STRING_QUIT], NULL }
	};

	// std::cout << __func__ << std::endl; Might be useful
	std::cout << Functions::fullScreenBox<2, 1>(options);
	return;
};
