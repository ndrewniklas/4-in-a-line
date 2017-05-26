// CS 420 4-in-a-line.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>

#include "UserInterface.h"
#include "Board.h"


int main()
{
	UserInterface ui;
	Board game;
	char result = ui.welcome();
	std::cout << game;

	//ui.exit();
	system("pause");
    return 0;
}

