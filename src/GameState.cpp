// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include "GameState.hpp"
#include "Languages.hpp"
#include <stdio.h>
#include <stdlib.h>


bool GameState::gameOver = false;
int GameState::argc = 0;
char** GameState::argv = NULL;
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

void GameState::init(int argc, char** argv) {
	GameState::argc = argc;
	GameState::argv = argv;
	GameState::reset();
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
