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
#include "Timer.h"
using namespace std;

void gameLoop(Board*, UserInterface);
bool plrTakeTurn(char player, UserInterface ui, Board* game);
bool botTakeTurn(char player, UserInterface ui, Board* game);
char bot = 'X', human = 'O', first;
int botThinkTime;
int main()
{

	UserInterface ui;
	Board* game = new Board();
	char result = ui.welcome();
	if (result == 'y') first = human;
	else first = bot;
	botThinkTime = ui.botThinkTime();
	gameLoop(game, ui);
	//ui.exit();
	system("pause");
	delete game;
    return 0;
}

void gameLoop(Board* game, UserInterface ui) {
	while (true) {
		cout << *(game);
	
		if (bot == first) {
			//Player 1 is 
			bool botWin = botTakeTurn(bot, ui, game);
			if (botWin) break;
			//Player 2 is human
			bool plrWin = plrTakeTurn(human, ui, game);
			if (plrWin == true) break;
		}
		else {
			//Player 1 is human
			bool plrWin = plrTakeTurn(human, ui, game);
			if (plrWin == true) break;
			//Player 2 is bot
			bool botWin = botTakeTurn(bot, ui, game);
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
	cout << "Score:" << game->calculateScore() << endl;
	if (game->checkWinCondition(pPos[0], atoi(&pPos[1]))) {
		cout << "Player wins the game!\n";
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
	cout << "Score:" << game->calculateScore() << endl;
	if (game->checkWinCondition(pPos[0], atoi(&pPos[1]))) {
		cout << "Computer wins the game!\n";
		return true;
	}
	return false;
}

bool timerFinished(std::function<void(void)> const & callback) {
	Timer t;
	t.Start(chrono::seconds(2), callback);
	t.Stop();
	return true;
}