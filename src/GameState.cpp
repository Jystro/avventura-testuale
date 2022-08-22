// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include "GameState.hpp"
#include "Languages.hpp"
#include <stdio.h>
#include <stdlib.h>

bool GameState::gameOver = false;
unsigned int GameState::round = 0;
void(*GameState::gameFunction)() = NULL;
void(*GameState::prevGameFunction)() = NULL;

GameState::Settings GameState::settings = {
	.language = Languages::Language::EN
};


void GameState::resetSettings() {
	GameState::settings = {
		.language = Languages::Language::EN
	};
	return;
};

void GameState::reset() {
	GameState::gameOver = false;
	GameState::round = 0;
	return;
};

unsigned int GameState::increaseRound() {
	GameState::round++;
	return GameState::round;
};
