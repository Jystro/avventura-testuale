// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#include "Languages.hpp"



namespace GameState {
	// extern tells compiler variable exists somewhere, doesn't care where
	// pack = how to pack structures (remove margin)
#pragma pack(push, 1)
	/**
	 * @brief	Persisting settings
	*/
	extern struct Settings {
		Languages::Language language; /**<	Language of the game */
	} settings;
#pragma pack(pop)
	extern int argc; /**<						Number of arguments passed to the program */
	extern char** argv; /**<					Arguments passed to the program */
	extern void(*gameFunction)(); /**<		Function called by the game loop */
	extern void(*prevGameFunction)(); /**<	Function called previously by the game loop */

	void init(int argc, char** argv); /**<	Init all GameState variables */
	void resetSettings(); /**<					Reset GameState::settings */
	void writeSettings(); /**<					Write GameState::settings to file */
	void readSettings(); /**<					Read GameState::settings from file */
}; // GAMESTATE

#endif // GAMESTATE_HPP
