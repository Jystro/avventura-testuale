// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Languages.hpp"

namespace GameState {
	// extern tells compiler variable exists somewhere, doesn't care where
	// pack = how to pack structures (remove margin)
#pragma pack(push, 1)
	extern struct Settings {
		Languages::Language language;
	} settings;
#pragma pack(pop)
	extern bool gameOver;
	extern int argc;
	extern char** argv;
	extern void(*gameFunction)();
	extern void(*prevGameFunction)();
	extern unsigned int round;

	unsigned int increaseRound();
	void init(int argc, char** argv);
	void reset();
	void resetSettings();
	void writeSettings();
	void readSettings();
}; // GAMESTATE

#endif // GAMESTATE_HPP
