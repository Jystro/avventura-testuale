// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

#include <iostream>

#include "GameState.hpp"
#include "Functions.hpp"

int main(int argc, char** argv) {

	// init game state
	GameState::init(argc, argv);

	// init void(*fun)() to the menu
	GameState::gameFunction = Functions::startMenu;

	// Game loop
	while(!GameState::gameOver) {
		try {
			GameState::gameFunction();
		} catch(const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			GameState::prevGameFunction();
		};
	};

	return 0;
};
