// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Languages.hpp"

namespace GameState {
	// extern tells compiler variable exists somewhere, doesn't care where
	extern struct Settings {
		Languages::Language language;
		friend std::ostream& operator <<(std::ostream& os, GameState::Settings const& sett) {
			return os << std::to_string(static_cast<int>(sett.language));
		};
	} settings;
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
}; // GAMESTATE

#endif // GAMESTATE_HPP
