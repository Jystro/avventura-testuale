// Authors: Lorenzo Colombo, Lorenzo De Filippo, Giovanni Nerviani
#include "InputParser.hpp"
#include <iostream>

int main(int argc, char** argv) {
	InputParser input(argc, argv);
	if(!input.cmdOptionExists("-w") || !input.cmdOptionExists("-h")) {
		std::cerr << "Please provide width and height in pixels" << std::endl;
		return 1;
	};
	const int width = std::stoi(input.getCmdOption("-w"));
	const int height = std::stoi(input.getCmdOption("-h"));

	std::cout << width << 'x' << height << std::endl;
	return 0;
};
