//
// Created by Alec Moran on 12/30/21.
//

#ifndef DATAPOOL_H
#define DATAPOOL_H

#include "Player.h"

class Datapool{
public:
    static int numPlayers;
    static double goalRatio;
    static int startingCash;
    static int goalCash;
    enum betType{
        passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome
    };
    static betType strategy;
    static bool allGameResults[];
    static int numWins;
    static int numLosses;
    static int numBets;
    static double winRatio;

    Datapool(int numPlayers, int startingCash, double goalRatio, betType strategy);

    void gatherData();

    void printResults();

};

#endif //DATAPOOL_H
