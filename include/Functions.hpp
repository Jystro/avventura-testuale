// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

/**
 * @file		Functions.hpp
 * @brief	All functions related to gameFunction
 * @see		GameState
 *
 *	All functions to point from GameState::gameFunction and relative helpers that might be useful elsewhere
*/
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>




/**
 * @brief	Namespace to wrap all functions necessary for gameplay
*/
namespace Functions {

	/**
	 * @brief	Creates a box with options from given size
	 * Creates a box with strings separated by specific border characters and title, of given size
	 * @see		Entry
	 * @see		Border
	 *
	 * @param	rows		The number of rows of entries
	 * @param	columns	The number of columns of entries
	 * @param	title		The title of the box
	 * @param	entries	A matrix of strings of rows * columns
	 * @param	width		The width of the box in terminal's columns
	 * @param	height	The height of the box in terminal's rows
	 *
	 * @return	A string with the box
	*/
	template<const unsigned int rows, const unsigned int columns>
	std::string box(const std::string title, const std::string (&entries)[rows][columns], const unsigned int width, unsigned int height);

	/**
	 * @brief	Creates a box with options and the size of the terminal window
	 * Creates a box with strings separated by specific border characters and title, the size of the window
	 * @see		Functions::box
	 * @see		getTerminalSize
	 *
	 * @param	rows		The number of rows of entries
	 * @param	columns	The number of columns of entries
	 * @param	title		The title of the box
	 * @param	entries	A matrix of strings of rows * columns
	 *
	 * @return	A string with the box
	*/
	template<const unsigned int rows, const unsigned int columns>
	std::string fullScreenBox(const std::string title, const std::string (&entries)[rows][columns]);


	/**
	 * @brief	Creates a box containing text
	 * Creates a box with a text with 10% margin, border of specific characters and title, of given size
	 * @see		Border
	 *
	 * @param	title		The title of the box
	 * @param	text		The text to be displayed
	 * @param	width		The width of the box in terminal's columns
	 * @param	height	The height of the box in terminal's rows
	 *
	 * @return	A string with the box
	*/
	std::string textBox(const std::string title, std::string text, const unsigned int width, unsigned int height);

	/**
	 * @brief	Creates a box with text and the size of the terminal window
	 * Creates a box with a text with 10% margin, border of specific characters and title, the size of the window
	 * @see		Functions::textBox
	 * @see		getTerminalSize
	 *
	 * @param	title		The title of the box
	 * @param	text		The text to be displayed
	 *
	 * @return	A string with the box
	*/
	std::string fullScreenTextBox(const std::string title, const std::string text);




	/*@{*/
	/**
	 * @brief	Function to manage the settings page
	 * Presents the user with a fullScreenBox of entries and wait for a selection using drawBoxAndSetNextFunctionOnUserInput; then saves the updated settings to file
	 *
	 * @see		Entry
	 * @see		setLanguage
	 * @see		resetSettings
	 * @see		drawBoxAndSetNextFunctionOnUserInput
	 * @see		GameState::writeSettings
	*/
	void settings();

	/**
	 * @brief	Exits the program
	 * Exits the program and farewells the user
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
	void startMenu();


	/**
	 * @brief	Namespace containing functions for the phase 1 of the story
	*/
	namespace Phase1 {

		/**
		 * @brief	Function to the start of the story
		*/
		void start();
	};
	/*@}*/
}; // FUNCTIONS

#endif // FUNCTIONS_HPP
