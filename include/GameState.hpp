// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Languages.hpp"

namespace GameState {
	// extern tells compiler variable exists somewhere, doesn't care where
	extern bool gameOver;
	extern void(*gameFunction)();
	extern void(*prevGameFunction)();
	extern unsigned int round;
	extern Languages::Language language;

	unsigned int increaseRound();
	void reset();
}; // GAMESTATE

#endif // GAMESTATE_HPP
