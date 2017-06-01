#pragma once

#include <iostream>
class UserInterface {
public:
	UserInterface();
	~UserInterface();

	char welcome();
	std::string enterPosition();
	int exit();
	int botThinkTime();
};

