//
// Created by Alec Moran on 12/30/21.
//
#include <iostream>
#include "Datapool.h"

Datapool::Datapool(int numPlayers, int startingCash, double goalRatio, betType strategy) {
    this->numPlayers = numPlayers;
    this->startingCash = startingCash;
    this->goalCash = (int)(startingCash * goalRatio);
    this->goalRatio = goalRatio;
    this->strategy = strategy;
}

void Datapool::gatherData(){
    bool allGameResults[numPlayers];
    for (int i = 0; i < numPlayers; i++){
        Player nextPlayer = Player(Player::strategy, startingCash, goalCash);
        nextPlayer.playStrategy();
        allGameResults[i] = nextPlayer.getResult();
        if (allGameResults[i] == true){
            ++numWins;
        }
        else {
            ++numLosses;
        }
    }
    winRatio = (double)numWins/(double)numLosses;
}

void Datapool::printResults() {
    cout << "Strategy chosen" << strategy << endl;
    cout << "Number of wins:" << numWins << ", Number of losses: " << numLosses << endl;
    cout << "Win percentage: " << winRatio << endl;
    cout << "House advantage: " << 50.0 - winRatio << endl;
}