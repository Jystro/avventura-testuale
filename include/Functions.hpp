// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include <cstdlib>
#include <ctime>

namespace Functions {

	template<const unsigned int rows, const unsigned int columns>
	std::string box(const std::string title, const std::string (&entries)[rows][columns], const unsigned int width, unsigned int height);

	std::string textBox(const std::string title, std::string text, const unsigned int width, unsigned int height);

	template<const unsigned int rows, const unsigned int columns>
	std::string fullScreenBox(const std::string title, const std::string (&entries)[rows][columns]);

	std::string fullScreenTextBox(const std::string title, const std::string text);


	// Game functions
	void settings();
	void quit();
	void startMenu();
	bool chance();

	namespace Phase1 {
		void start();
		void west();
		void north();
		void east();
		void south();
		void lookAround();
	};

	namespace Phase2 {
		namespace W {
			void obstacle();
			void lookAround();
			void climb();
			void ficus();
			void palm();
		}
	};

	namespace Phase3 {
		namespace W {
			void ficusEat();
			void ficusProceed();
			void ficusLookAround();
			void palmEat();
			void palmProceed();
			void palmLookAround();
		}
	}
	
};

namespace Phase4 {
	namespace W {
		void fight();
		void befriend();
		void run();
	}
} // FUNCTIONS

#endif // FUNCTIONS_HPP
