// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
//#include "InputParser.hpp"
#include "InputParser.hpp"
#include "GameState.hpp"
#include <iostream>

int main(int argc, char** argv) {

	// Parse width and height arguments
	InputParser input(argc, argv);
	if(!input.cmdOptionExists("-w") || !input.cmdOptionExists("-h")) {
		std::cerr << "Please provide width and height in pixels" << std::endl;
		return 1;
	};
	const int width = std::stoi(input.getCmdOption("-w"));
	const int height = std::stoi(input.getCmdOption("-h"));
	std::cout << width << 'x' << height << std::endl;

	// reset game state
	GameState::reset();

	// Game loop
	while(true) {	
		printf("%s", GameState::gameOver ? "true" : "false");
	};

	return 0;
};
