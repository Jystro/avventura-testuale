#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

namespace Functions {
	struct terminalSize {
		unsigned int x;
		unsigned int y;
	};

	struct item {
		std::string text;
		void(*next_ptr)();
	};

	const char border_horizontal[4] = "═";
	const char border_vertical[4] = "║";
	const char border_top_left[4] = "╔";
	const char border_top_right[4] = "╗";
	const char border_bottom_left[4] = "╚";
	const char border_bottom_right[4] = "╝";

	Functions::terminalSize getTerminalSize();

	void startMenu();
}; // FUNCTIONS

#endif // FUNCTIONS_HPP
