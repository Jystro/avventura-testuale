#include <iostream>
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

void Functions::startMenu() {
	return;
};
