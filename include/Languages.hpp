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
		STRING_Settings,
		STRING_English,
		STRING_Italian,
		STRING_Language,
		STRING_Back
	};
	extern std::string* languages[];
}; // LANGUAGES

#endif // LANGUAGES_HPP
