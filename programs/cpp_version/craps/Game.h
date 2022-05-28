// Game.h
#ifndef GAME_H
#define GAME_H

#include "Dice.h"

class Game {

	public:
		enum betType {
			passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome
		};
		enum gameState {
			comeOut, activeGame
		};
		int startingCash;
		int wagerAmount;
		int goalCash;
		int numBets;
		betType strategy;
		gameState currentGameState;
		Dice dice;

		Game();
		Game(int strategyInt, int startAmount, int goalAmount);

		gameState getGameState();

		void setGameState(gameState inputGameState);

		bool rolledPass(int diceRoll);

		bool rolledCraps(int diceRoll);

		int rollField(int diceRoll, int fieldMultiplier);

		int playThePoint(int currentCash, int wagerAmount, int diceRoll, betType strategy);

		int playComeOut(int currentCash, int wagerAmount, int diceRoll, betType strategy);

		bool pointEstablished(int firstDiceRoll);

		bool playCraps();

};

#endif
