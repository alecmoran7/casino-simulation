// Game.h
#ifndef GAME_H
#define GAME_H

#include "Dice.cc"
class Game {

    public:
        static enum betType {passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome};
        static enum gameState {comeOut, activeGame};
        static int startingCash;
        static int wagerAmount;
        static int goalCash;
        static betType strategy;
        static gameState currentGameState;
        static Dice dice;

        Game(betType inputStrategy, int startAmount, int goalAmount);

        gameState getGameState(gameState currentGameState);

        void setGameState(gameState inputGameState);

        int playCraps();


};
#endif