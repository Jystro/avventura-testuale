#ifndef LANGUAGES_HPP
#define LANGUAGES_HPP

#include <string>

namespace Languages {
	enum Language {
		EN, IT
	};
	enum {
		STRING_MENU,
		STRING_START,
		STRING_QUIT,
		STRING_SETTINGS
	};
	extern std::string* languages[];
}; // LANGUAGES

#endif // LANGUAGES_HPP
