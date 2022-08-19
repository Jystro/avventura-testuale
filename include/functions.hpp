#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

namespace Functions {
	struct terminalSize {
		unsigned int x;
		unsigned int y;
	};

	struct menuItem {
		std::string text;
		void(*next_ptr)();
	};

	Functions::terminalSize getTerminalSize();

	void startMenu();
}; // FUNCTIONS

#endif // FUNCTIONS_HPP
