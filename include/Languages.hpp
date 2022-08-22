#ifndef LANGUAGES_HPP
#define LANGUAGES_HPP

#include <string>

namespace Languages {
	enum Language {
		EN, IT
	};
	enum {
		STRING_Menu,
		STRING_Start,
		STRING_Quit,
		STRING_Settings
	};
	extern std::string* languages[];
}; // LANGUAGES

#endif // LANGUAGES_HPP
