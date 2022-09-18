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
		STRING_Proceed,
		STRING_Boat,
		STRING_Fight,
		STRING_Befriend,
		STRING_Run,
		STRING_Enter,
		STRING_Ignore,
		STRING_Trust
	};
	enum {
		STATUS_Bye,
		STATUS_Unavailable_Option,
		STATUS_Select_A_Language,
		STATUS_Select_An_Option,
		STATUS_Enter_A_Command,
		STATUS_Press_Enter_To_Continue
	};

	/**
	 * enum with available story parts
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
		STORY_Phase2W_Climb_Palm,
		STORY_Phase2W_Ficus,
		STORY_Phase2W_Palm,
		STORY_Phase2N_Obstacle,
		STORY_Phase2N_LookAround,
		STORY_Phase2E_Obstacle,
		STORY_Phase2E_LookAround,
		STORY_Phase2E_Boat,
		STORY_Phase3W_FicusEat,
		STORY_Phase3W_FicusProceed,
		STORY_Phase3W_FicusLookAround,
		STORY_Phase3W_PalmEat,
		STORY_Phase3W_PalmProceed,
		STORY_Phase3W_PalmLookAround,
		STORY_Phase3N_Jaguar,
		STORY_Phase3N_JaguarClimb,
		STORY_Phase3N_JaguarLookAround,
		STORY_Phase3N_Hornet,
		STORY_Phase3N_HornetEat,
		STORY_Phase3N_HornetProceed,
		STORY_Phase3N_HornetLookAround,
		STORY_Phase3E_Fight,
		STORY_Phase3E_Befriend,
		STORY_Phase4W_Befriend,
		STORY_Phase4W_Run,
		STORY_Phase4N_VillageEnter,
		STORY_Phase4N_VillageIgnore,
		STORY_Phase4N_VillageLookAround,
		STORY_Phase4E_Trust,
		STORY_Phase4E_Run,
		STORY_Phase5N_FruitEat,
		STORY_Phase5N_FruitIgnore
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
		TITLE_Palm,
		TITLE_Square,
		TITLE_Tourists,
		TITLE_Hunter,
		TITLE_Jaguar,
		TITLE_Village,
		TITLE_HornetNest
	};


	extern std::string* strings[]; /**< 2D Array with language on first array and strings in second one */
	extern std::string* status[]; /**< 2D Array with language on first array and status messages in second one */
	extern std::string* story[]; /**< 2D Array with language on first array and stories in second one */
	extern std::string* titles[]; /**< 2D Array with language on first array and titles in second one */
}; // LANGUAGES

#endif // LANGUAGES_HPP
