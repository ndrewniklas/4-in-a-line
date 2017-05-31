// CS 420 4-in-a-line.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>

#include "UserInterface.h"
#include "Board.h"

using namespace std;

void gameLoop(Board*, UserInterface);

int main()
{
	UserInterface ui;
	Board* game = new Board();
	char result = ui.welcome();
	gameLoop(game, ui);
	//ui.exit();
	system("pause");
    return 0;
}

void gameLoop(Board* game, UserInterface ui) {
	while (true) {
		cout << *(game);
		//Player 1's turn
		string p1Pos = ui.enterPosition();
		while (!game->setPiece(p1Pos[0], atoi(&p1Pos[1]), 'O')) {
			cout << "Not a legal move!\n";
			p1Pos = ui.enterPosition();
		}
		cout << *(game);
		if (game->checkWinCondition(p1Pos[0], atoi(&p1Pos[1]))) {
			cout << "Player 1 wins the game!\n";
			break;
		}
		//Player 1's turn
		string p2Pos = ui.enterPosition();
		while (!game->setPiece(p2Pos[0], atoi(&p2Pos[1]), 'X')) {
			cout << "Not a legal move!\n";
			p2Pos = ui.enterPosition();
		}
		cout << *(game);		
		if (game->checkWinCondition(p2Pos[0], atoi(&p2Pos[1]))) {
			cout << "Player 2 wins the game!\n";
			break;
		}
	}
}
