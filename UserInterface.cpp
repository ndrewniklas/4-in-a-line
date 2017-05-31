#include "UserInterface.h"
#include <string>
#include <locale>  

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

std::string UserInterface::enterPosition() {
	std::locale loc;
	std::string input;
	std::cout << "Choose your next move:";
	std::cin >> input;
	while (input.length() != 2 || !std::isalpha(input[0],loc) || !std::isdigit(input[1],loc)) {
		std::cout << "Not a legal move!\nChoose your next move:";
		std::cin >> input;
	}
	return input;
}

int UserInterface::exit() {
	std::cin.ignore();
	std::cout << "Press any key to exit . . . ";
	std::cin.get();
	return 0;
}


UserInterface::~UserInterface() {
}
