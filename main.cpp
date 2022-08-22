// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include "GameState.hpp"
#include "Functions.hpp"
#include <iostream>

int main(int argc, char** argv) {

	// reset game state
	GameState::reset();

	// init void(*fun)() to the menu
	GameState::gameFunction = Functions::startMenu;

	// Game loop
	while(true) {	
		GameState::gameFunction();
		//printf("%s", GameState::gameOver ? "true" : "false");
	};

	return 0;
};
