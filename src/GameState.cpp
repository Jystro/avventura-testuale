#include "GameState.hpp"

unsigned int GameState::increaseRound() {
	GameState::round++;
	return GameState::round;
};


void GameState::reset() {
	GameState::gameOver = false;
	GameState::round = 0;
	return;
};
