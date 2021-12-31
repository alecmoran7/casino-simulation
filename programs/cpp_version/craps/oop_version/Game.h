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
    static int startingCash;
    static int wagerAmount;
    static int goalCash;
    static int numBets;
    static betType strategy;
    static gameState currentGameState;
    static Dice dice;

    Game();

    Game(betType inputStrategy, int startAmount, int goalAmount);

    gameState getGameState(gameState currentGameState);

    void setGameState(gameState inputGameState);

    int playCraps();


};

#endif