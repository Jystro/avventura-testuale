// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

/**
 * @file		GameState.hpp
 * @brief	Contains all variables and functions needed to know or change the state of the game
*/
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Languages.hpp"

/**
 * @brief	Namespace containing variables and functions related to the game state
 * Contains all variables and functions needed to know or change the state of the game and settings
*/
namespace GameState {

	// extern tells compiler variable exists somewhere, doesn't care where
	// pack = how to pack structures (remove margin)
#pragma pack(push, 1)
	/**
	 * @brief	A struct containing the settings
	*/
	extern struct Settings {
		/*@{*/
		Languages::Language language; /**< The language of the game */
		/*@}*/
	} settings;
#pragma pack(pop)

	extern bool gameOver; /**< Whether the game is over */
	extern int argc; /**< Number of arguments passed to the exectuable */
	extern char** argv; /**< Arguments passed to the executable as arrays of chars */
	extern void(*gameFunction)(); /**< Pointer to void function called every game loop in main. @see main.cpp */
	extern void(*prevGameFunction)(); /**< Pointer to void function to call when going back */




	/**
	 * @brief	Function to init GameState variables
	 * Initializes GameState variables to their initial values and reads GameState::settings from file
	 * @see		GameState::readSettings
	 * @see		GameState::reset
	 *
	 * @param	argc	Number of args
	 * @param	argv	Array of args
	*/
	void init(int argc, char** argv);


	/**
	 * @brief	Function to reset GameState variables
	 * Reset GameState variables to their initial values
	*/
	void reset();


	/**
	 * @brief	Function to reset GameState::settings to it's default value
	 * Reset GameState::settings to it's default value
	*/
	void resetSettings();


	/**
	 * @brief	Function to write GameState::settings to file
	*/
	void writeSettings();


	/**
	 * @brief	Function to read GameState::settings to file
	*/
	void readSettings();
}; // GAMESTATE

#endif // GAMESTATE_HPP
