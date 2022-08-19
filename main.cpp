// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include "GameState.hpp"
#include "Functions.hpp"
#include <iostream>

// void funtion that changes static pointer to void function
// (no return)

void f2();
void f1() {
	std::cout << "Hello ";
	GameState::fun = f2;
	return;
};

void f2() {
	std::cout << "World!" << std::endl;
	return;
};

int main(int argc, char** argv) {

	// reset game state
	GameState::reset();

	// init void(*fun)() to the menu
	GameState::fun = Functions::startMenu;

	GameState::fun();
	// Game loop
	while(true) {	
		//printf("%s", GameState::gameOver ? "true" : "false");
	};

	return 0;
};
