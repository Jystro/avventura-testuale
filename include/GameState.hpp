// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Languages.hpp"

namespace GameState {
	// extern tells compiler variable exists somewhere, doesn't care where
	extern struct Settings {
		Languages::Language language;
	} settings;
	extern bool gameOver;
	extern void(*gameFunction)();
	extern void(*prevGameFunction)();
	extern unsigned int round;

	unsigned int increaseRound();
	void reset();
	void resetSettings();
}; // GAMESTATE

#endif // GAMESTATE_HPP
