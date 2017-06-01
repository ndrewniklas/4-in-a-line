// CS 420 4-in-a-line.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>
#include <thread>

#include "UserInterface.h"
#include "Board.h"

using namespace std;

void gameLoop(Board*, UserInterface);
bool plrTakeTurn(char player, UserInterface ui, Board* game);
bool botTakeTurn(char player, UserInterface ui, Board* game);
char botPlayer, first = 'X', second = 'O';
int botThinkTime;
int main()
{
	UserInterface ui;
	Board* game = new Board();
	char result = ui.welcome();
	if (result == 'y') botPlayer = second;
	else botPlayer = first;
	botThinkTime = ui.botThinkTime();
	gameLoop(game, ui);
	//ui.exit();
	system("pause");
    return 0;
}

void gameLoop(Board* game, UserInterface ui) {
	while (true) {
		cout << *(game);
	
		if (botPlayer == first) {
			//Player 1 is 
			bool botWin = botTakeTurn(first, ui, game);
			if (botWin) break;
			//Player 2 is human
			bool plrWin = plrTakeTurn(second, ui, game);
			if (plrWin == true) break;
		}
		else if (botPlayer == second) {
			//Player 1 is human
			bool plrWin = plrTakeTurn(first, ui, game);
			if (plrWin == true) break;
			//Player 2 is bot
			bool botWin = botTakeTurn(second, ui, game);
			if (botWin == true) break;
		}

	}
}

bool plrTakeTurn(char player,UserInterface ui, Board* game) {
	string pPos = ui.enterPosition();
	while (!game->setPiece(pPos[0], atoi(&pPos[1]), player)) {
		cout << "Not a legal move!\n";
		pPos = ui.enterPosition();
	}
	cout << *(game);
	if (game->checkWinCondition(pPos[0], atoi(&pPos[1]))) {
		if (player == first)
			cout << "Player 1 wins the game!\n";
		else if (player == second)
			cout << "Player 2 wins the game!\n";
		return true;
	}
	return false;
}
bool botTakeTurn(char player, UserInterface ui, Board* game) {
	//Do bot stuff, currently just another player
	string pPos = ui.enterPosition();
	while (!game->setPiece(pPos[0], atoi(&pPos[1]), player)) {
		cout << "Not a legal move!\n";
		pPos = ui.enterPosition();
	}
	cout << *(game);
	if (game->checkWinCondition(pPos[0], atoi(&pPos[1]))) {
		if(player == first)
			cout << "Player 1 wins the game!\n";
		else if(player == second)
			cout << "Player 2 wins the game!\n";
		return true;
	}
	return false;
}
