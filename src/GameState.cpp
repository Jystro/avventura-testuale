// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani

/**
 * @file		GameState.cpp
 * @brief	Contains all variables and functions needed to know or change the state of the game
*/
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "GameState.hpp"
#include "Languages.hpp"




bool GameState::gameOver = false;
int GameState::argc = 0;
char** GameState::argv = NULL;
void(*GameState::gameFunction)() = NULL;
void(*GameState::prevGameFunction)() = NULL;

GameState::Settings GameState::settings = {
	.language = Languages::Language::EN
};




void GameState::init(int argc, char** argv) {
	GameState::argc = argc;
	GameState::argv = argv;

	GameState::readSettings();

	GameState::reset();
	return;
};


void GameState::reset() {
	GameState::gameOver = false;
	return;
};


void GameState::resetSettings() {
	GameState::settings = {
		.language = Languages::Language::EN
	};
	return;
};


void GameState::writeSettings() {
	std::string executableFolder(GameState::argv[0]);
	executableFolder = executableFolder.substr(0, executableFolder.find_last_of("\\/") + 1);

	try {
		std::ofstream file(executableFolder + "settings.bin", std::ios::out | std::ios::binary | std::ios::trunc);
		file.write(reinterpret_cast<char*>(&GameState::settings), sizeof(GameState::Settings));
	} catch(const std::exception& e) {
		std::cerr << "Unable to open file " << executableFolder << "settings.bin" << e.what() << std::endl;
	};

	return;
};


void GameState::readSettings() {
	std::string executableFolder(GameState::argv[0]);
	executableFolder = executableFolder.substr(0, executableFolder.find_last_of("\\/") + 1);

	try {
		std::ifstream file(executableFolder + "settings.bin", std::ios::in | std::ios::binary);
		file.read(reinterpret_cast<char*>(&GameState::settings), sizeof(GameState::Settings));
	} catch(const std::exception& e) {
		std::cerr << "Unable to open file " << executableFolder << "settings.bin " << e.what() << std::endl;
	};

	return;
};
