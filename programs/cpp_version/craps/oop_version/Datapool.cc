//
// Created by Alec Moran on 12/30/21.
//
#include <iostream>
#include "Datapool.h"

Datapool::Datapool(int numPlayers, int startingCash, double goalRatio, int strategyInt) {
    this->numPlayers = numPlayers;
    this->startingCash = startingCash;
    this->goalCash = (int)(startingCash * goalRatio);
    this->goalRatio = goalRatio;
    this->strategyInt = strategyInt;
    numWins = 0;
    numLosses = 0;
}

void Datapool::gatherData(){
    bool allGameResults[numPlayers];
    for (int i = 0; i < numPlayers; i++){
        Player nextPlayer = Player(strategyInt, startingCash, goalCash);
        nextPlayer.playStrategy();
        allGameResults[i] = nextPlayer.getResult();
        if (allGameResults[i] == true){
            clog << "Player" << i << " won" << endl;
            ++numWins;
        }
        else {
            clog << "Player" << i << " lost" << endl;
            ++numLosses;
        }

    }
    winRatio = (double)numWins/(double)(numLosses+numWins);
}

void Datapool::printResults() {
    cout << "Strategy chosen: " << strategyInt << endl;
    cout << "Number of wins: " << numWins << ", Number of losses: " << numLosses << endl;
    cout << "Win percentage: " << winRatio * 100 << "%" << endl;
    cout << "House advantage: " << 50.0 - (winRatio*100) << "%" << endl;
}