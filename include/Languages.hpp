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
		STORY_Phase2W_Ficus,
		STORY_Phase2W_Palm,
		STORY_Phase2N_Obstacle,
		STORY_Phase2N_LookAround,
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
		STORY_Phase4N_VillageLookAround
	};
	extern std::string* strings[];
	extern std::string* status[];
	extern std::string* story[];
}; // LANGUAGES

#endif // LANGUAGES_HPP
