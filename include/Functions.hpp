// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include <cstdlib>
#include <ctime>

namespace Functions {

	template<const unsigned int rows, const unsigned int columns>
	std::string box(const std::string title, const std::string (&entries)[rows][columns], const unsigned int width, unsigned int height);

	std::string textBox(const std::string title, std::string text, const unsigned int width, unsigned int height);

	template<const unsigned int rows, const unsigned int columns>
	std::string fullScreenBox(const std::string title, const std::string (&entries)[rows][columns]);

	std::string fullScreenTextBox(const std::string title, const std::string text);


	// Game functions
	void settings();
	void quit();
	/**
	 * @brief	Presents the user with the main menu
	 *
	 * @see		Entry
	 * @see		Functions::settings
	 * @see		Functions::quit
	 * @see		drawBoxAndSetNextFunctionOnUserInput
	*/
	void mainMenu();
	void introduction();
	inline bool chance();

	namespace Phase1 {
		void start(); /**<		Function to the start of the story */
		void west(); /**<			Function called when the player selects west */
		void north(); /**<		Function called when the player selects north */
		void east(); /**<			Function called when the player selects east */
		void south(); /**<		Function called when the player selects north */
		void lookAround(); /**<	Function called when the player decides to look around */
	};

	/**
	 * @brief	Namespace containing functions for the phase 2 of the story
	*/
	namespace Phase2 {
		namespace W {
			void obstacle(); /**<	Function called when the player meets an obstacle */
			void lookAround(); /**<	Function called when the player decides to look around */
			void climb(); /**<		Function called when the player decides to climb */
			void ficus(); /**<		Function called when the player is on the ficus tree */
			void palm(); /**<			Function called when the player is on the ficus tree */
		};

		namespace N {
			void obstacle();
			void lookAround();
		};

		namespace E {
			void obstacle();
			void lookAround();
			void drink();
			void boat();
		};
	};

	namespace Phase3 {
		namespace W {
			void ficusEat();
			void ficusProceed();
			void ficusLookAround();
			void palmEat();
			void palmProceed();
			void palmLookAround();
		};

		namespace N {
			void jaguar();
			void jaguarFight();
			void jaguarRun();
			void jaguarClimb();
			void jaguarLookAround();
			void hornet();
			void hornetEat();
			void hornetProceed();
			void hornetLookAround();
		};
	};
	
	namespace Phase4 {
		namespace W {
			void fight();
			void befriend();
			void run();
		};

		namespace N {
			void villageEnter();
			void villageIgnore();
			void villageLookAround();
		};
	};

	namespace Phase5 {
		namespace N {
			void fruitEat();
			void fruitIgnore();
		};
	};

	/*@}*/
}; // FUNCTIONS


#endif // FUNCTIONS_HPP
