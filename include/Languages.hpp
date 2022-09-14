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
		STRING_Reset_settings,
		STRING_Bye,
		STRING_West,
		STRING_North,
		STRING_East,
		STRING_South,
		STRING_Look_Around,
		STRING_Climb,
		STRING_Fig,
		STRING_Palm,
		STRING_Drink,
		STRING_Eat,
		STRING_Proceed
	};

	/**
	 * @brief Enum with available status messages
	*/
	enum {
		STATUS_Bye,
		STATUS_Unavailable_Option,
		STATUS_Select_A_Language,
		STATUS_Select_An_Option,
		STATUS_Enter_A_Command,
		STATUS_Press_Enter_To_Continue
	};

	/**
	 * @brief Enum with available story parts
	*/
	enum {
		STORY_Intro,
		STORY_Phase1_Start,
		STORY_Phase1_West,
		STORY_Phase1_North,
		STORY_Phase1_East,
		STORY_Phase1_South,
		STORY_Phase1_LookAround,
		STORY_Phase2W_Obstacle,
		STORY_Phase2W_LookAround,
		STORY_Phase2W_Climb,
		STORY_Phase2W_Climb_Fig,
		STORY_Phase2W_Climb_Palm
	};

	/**
	 * @brief Enum with available box titles
	*/
	enum {
		TITLE_Language,
		TITLE_Settings,
		TITLE_Main_Menu,
		TITLE_Prologue,
		TITLE_Crossroad,
		TITLE_Forest,
		TITLE_River,
		TITLE_Fig,
		TITLE_Palm
	};


	extern std::string* strings[]; /**< 2D Array with language on first array and strings in second one */
	extern std::string* status[]; /**< 2D Array with language on first array and status messages in second one */
	extern std::string* story[]; /**< 2D Array with language on first array and stories in second one */
	extern std::string* titles[]; /**< 2D Array with language on first array and titles in second one */
}; // LANGUAGES

#endif // LANGUAGES_HPP
