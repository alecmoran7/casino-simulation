//
// Created by Alec Moran on 12/30/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"

class Player {
public:
    int startingCash;
    int goalCash;
//    enum betType {
//        passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome
//    };
    int strategyInt;
    Game game;
    bool wasSuccessful;

    Player(int strategyInt, int startAmount, int goalAmount);
    ~Player();
    void playStrategy();

    bool getResult();
};

#endif //PLAYER_H
