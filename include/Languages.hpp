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
		STRING_Proceed
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
		STROY_Phase2E_Boat,
		STORY_Phase3W_FicusEat,
		STORY_Phase3W_FicusProceed,
		STORY_Phase3W_FicusLookAround,
		STORY_Phase3W_PalmEat,
		STORY_Phase3W_PalmProceed,
		STORY_Phase3W_PalmLookAround,
		STORY_Phase3N_jaguar,
		STORY_Phase3N_jaguarClimb,
		STORY_Phase3N_jaguarLookAround,
		STORY_Phase3N_hornet,
		STORY_Phase3N_hornetEat,
		STORY_Phase3N_hornetProceed,
		STORY_Phase3N_hornetLookAround,
		STORY_Phase4W_Befriend,
		STORY_Phase4W_Run,
		STORY_Phase4N_VillageEnter,
		STORY_Phase4N_VillageIgnore,
		STORY_Phase4N_VillageLookAround,
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
		TITLE_Palm
	};


	extern std::string* strings[]; /**< 2D Array with language on first array and strings in second one */
	extern std::string* status[]; /**< 2D Array with language on first array and status messages in second one */
	extern std::string* story[]; /**< 2D Array with language on first array and stories in second one */
	extern std::string* titles[]; /**< 2D Array with language on first array and titles in second one */
}; // LANGUAGES

#endif // LANGUAGES_HPP
