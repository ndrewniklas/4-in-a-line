#include "UserInterface.h"



UserInterface::UserInterface() {
}

char UserInterface::welcome() {
	char answer;
	std::cout << "Welcome to 4 in a Line\nWould you like to go first? ";
	std::cin >> answer;
	while (answer != 'y' && answer != 'n') {
		std::cout << "Invalid Input!\n Would you like to go first?(y/n)";
		std::cin >> answer;
		answer = tolower(answer);
	};
	return answer;
}

int UserInterface::exit() {
	std::cin.ignore();
	std::cout << "Press any key to exit . . . ";
	std::cin.get();
	return 0;
}


UserInterface::~UserInterface() {
}
