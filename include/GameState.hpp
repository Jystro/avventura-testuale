// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

namespace GameState {
	// extern tells compiler variable exists somewhere, doesn't care where
	extern bool gameOver;
	extern void(*fun)();
	extern unsigned int round;
	unsigned int increaseRound();
	void reset();
}; // GAMESTATE

#endif // GAMESTATE_HPP
