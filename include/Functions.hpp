#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

namespace Functions {

	struct terminalSize {
		unsigned int x;
		unsigned int y;
	};

	struct entry {
		std::string text;
		void(*next_ptr)();
	};

	const char border_horizontal[4] = "═";
	const char border_vertical[4] = "║";
	const char border_top_left[4] = "╔";
	const char border_top_right[4] = "╗";
	const char border_bottom_left[4] = "╚";
	const char border_bottom_right[4] = "╝";

	const char border_horizontal_connector_down[4] = "╦";
	const char border_horizontal_connector_up[4] = "╩";

	const char border_vertical_connector_right[4] = "╠";
	const char border_vertical_connector_left[4] = "╣";

	const char border_connector[4] = "╬";

	Functions::terminalSize getTerminalSize();
	template<const unsigned int rows, const unsigned int columns>
	std::string fullScreenBox(const struct Functions::entry (&entries)[rows][columns]);

	void startMenu();
}; // FUNCTIONS

#endif // FUNCTIONS_HPP
