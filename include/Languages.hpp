// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
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
		STRING_Back,
		STRING_Reset_settings
	};
	enum {
		STATUS_Bye,
		STATUS_Unavailable_Option,
		STATUS_Select_A_Language,
		STATUS_Select_An_Option,
		STATUS_Enter_A_Command
	};
	enum {
		STORY_Phase1_Start
	};
	extern std::string* strings[];
	extern std::string* status[];
	extern std::string* story[];
}; // LANGUAGES

#endif // LANGUAGES_HPP
