// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

/**
 * @file		Languages.hpp
 * @brief	All translations
 * All variables related to language translations
*/
#ifndef LANGUAGES_HPP
#define LANGUAGES_HPP

#include <string>

/**
 * @brief	Namespace with all translations and language related variables
*/
namespace Languages {

	/**
	 * @brief Enum with available languages
	*/
	enum Language {
		EN, IT
	};

	/**
	 * @brief Enum with available strings
	*/
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

	/**
	 * @brief Enum with available status messages
	*/
	enum {
		STATUS_Bye,
		STATUS_Unavailable_Option,
		STATUS_Select_A_Language,
		STATUS_Select_An_Option,
		STATUS_Enter_A_Command
	};

	/**
	 * @brief Enum with available story parts
	*/
	enum {
		STORY_Phase1_Start
	};


	extern std::string* strings[]; /**< 2D Array with language on first array and strings in second one */
	extern std::string* status[]; /**< 2D Array with language on first array and status messages in second one */
	extern std::string* story[]; /**< 2D Array with language on first array and stories in second one */
}; // LANGUAGES

#endif // LANGUAGES_HPP
