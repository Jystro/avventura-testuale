// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


#include <cstdlib>
#include <ctime>
#include <string>



namespace Functions {

	/**
	 * @brief	Prints a box of rows and columns
	 *
	 * @param	rows		Number of rows of the matrix
	 * @param	columns	Number of rows of the matrix
	 *
	 * @param	title		The title of the box
	 * @param	entries	A two-dimensional matrix of size rows * columns to be displayed
	 * @param	width		The width in terminal columns of the box
	 * @param	height	The height in terminal rows of the box
	 *
	 * @see		Functions::fullScreenBox
	 * 
	 * Prints a box of size width * height containing the strings in the matrix, one for each cell
	*/
	template<const unsigned int rows, const unsigned int columns>
	std::string box(const std::string title, const std::string (&entries)[rows][columns], const unsigned int width, unsigned int height);

	/**
	 * @brief	Prints a text box with text in the center
	 *
	 * @param	title		The title of the box
	 * @param	text		The text to be displayed
	 * @param	width		The width in terminal columns of the box
	 * @param	height	The height in terminal rows of the box
	 *
	 * @see		Functions::fullScreenTextBox
	 * 
	 * Prints a text box of size width * height containing the text with margin
	*/
	std::string textBox(const std::string title, std::string text, const unsigned int width, unsigned int height);

	/**
	 * @brief	Prints a box of rows and columns, the size of the screen
	 *
	 * @param	rows		Number of rows of the matrix
	 * @param	columns	Number of rows of the matrix
	 *
	 * @param	title		The title of the box
	 * @param	entries	A two-dimensional matrix of size rows * columns to be displayed
	 *
	 * @see		Functions::box
	 * 
	 * Prints a box the size of the screen containing the strings in the matrix, one for each cell
	*/
	template<const unsigned int rows, const unsigned int columns>
	std::string fullScreenBox(const std::string title, const std::string (&entries)[rows][columns]);

	/**
	 * @brief	Prints a  text box with text in the center, the size of the screen
	 *
	 * @param	title		The title of the box
	 * @param	text		The text to be displayed
	 *
	 * @see		Functions::textBox
	 * 
	 * Prints a text box the size of the screen containing the text with margin
	*/
	std::string fullScreenTextBox(const std::string title, const std::string text);



	// Game functions
	/*@{*/
	/**
	 * @brief	Presents the user with the settings menu
	 *
	 * @see		GameState::settings
	 * @see		Entry
	 * @see		Functions::mainMenu
	 * @see		Functions::quit
	 * @see		drawBoxAndSetNextFunctionOnUserInput
	*/
	void settings();

	/**
	 * @brief	Closes the program
	*/
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

	/**
	 * @brief	Presents the user with the end menu
	 *
	 * @see		Entry
	 * @see		Functions::settings
	 * @see		Functions::quit
	 * @see		drawBoxAndSetNextFunctionOnUserInput
	*/
	void endMenu();

	/**
	 * @brief	Tells the user the introduction to the story
	*/
	void introduction();

	/**
	 * @brief	Namespace containing functions for the phase 1 of the story
	*/
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
			void drink();
			void lookAround();
			void boat();
		};
	}

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

		namespace E {
			void fight();
			void befriend();
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

		namespace E {
			void trust();
			void run();
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
