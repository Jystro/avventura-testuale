// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

namespace Functions {

	struct TerminalSize {
		unsigned int x;
		unsigned int y;
	};

	struct Entry {
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


	Functions::TerminalSize getTerminalSize();

	template<const unsigned int rows, const unsigned int columns>
	std::string box(const std::string (&entries)[rows][columns], const unsigned int width, const unsigned int height);
	template<const unsigned int rows, const unsigned int columns>
	std::string fullScreenBox(const std::string (&entries)[rows][columns]);

	template<const unsigned int length>
	Functions::Entry entryFromString(const Functions::Entry (&entries)[length], std::string search);

	// Game functions
	void settings();
	void quit();
	void startMenu();
}; // FUNCTIONS

#endif // FUNCTIONS_HPP
