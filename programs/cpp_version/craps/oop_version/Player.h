//
// Created by Alec Moran on 12/30/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"

class Player {
public:
    static int startingCash;
    static int goalCash;
    enum betType {
        passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome
    };
    static betType strategy;
    static Game game;
    static bool wasSuccessful;

    Player(betType inputStrategy, int startAmount, int goalAmount);

    void playStrategy();

    bool getResult();
};

#endif //PLAYER_H
