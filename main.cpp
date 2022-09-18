// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

#include <iostream>

#include "Functions.hpp"
#include "GameState.hpp"



int main(int argc, char** argv) {

	// init game state
	GameState::init(argc, argv);

	// init void(*fun)() to the menu
	GameState::gameFunction = Functions::mainMenu;

	// Game loop
	while(true) {	
		try {
			GameState::gameFunction();
		} catch(const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			GameState::prevGameFunction();
		};
	};

	return 0;
};
