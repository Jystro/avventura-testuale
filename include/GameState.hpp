#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

namespace GameState {
	bool gameOver = false;
	unsigned int round = 0;
	unsigned int increaseRound();
	void reset();
};

#endif
