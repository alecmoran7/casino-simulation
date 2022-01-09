//
// Created by Alec Moran on 12/30/21.
//
#include <iostream>
#include <iomanip>
#include <cmath>
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

void Datapool::gatherPlayerData(){
    bool allGameResults[numPlayers];
    for (int i = 0; i < numPlayers; i++){
        Player nextPlayer = Player(strategyInt, startingCash, goalCash);
        nextPlayer.playStrategy();
        allGameResults[i] = nextPlayer.getResult();
        if (allGameResults[i] == true){
//            clog << "Player" << i << " won" << endl;
            ++numWins;
        }
        else {
//            clog << "Player" << i << " lost" << endl;
            ++numLosses;
        }
        for (int i = 0; i < nextPlayer.allRolls.size(); i++){
            int nextRoll = nextPlayer.allRolls[i];
//            clog << "nextRoll is " << nextRoll << endl << flush;
//            clog << "allRolls["<< nextRoll << "] is " << numRolls[nextRoll] << endl << flush;
            numRolls[nextRoll]++;
            totalNumRolls++;
        }
    }
    winRatio = (double)numWins/(double)(numLosses+numWins);
}

void Datapool::analyzeDiceData() {
    for (int i = 2; i <= 12; i++){
//        numRolls[i] = allRolls.at(i);
        int fracNumerator = 6 - abs(7-i);
        rollPercentage[i] = 100.00 * (1.00 - abs(1.00 - (double)(numRolls[i])/(double)(totalNumRolls) / (double)(fracNumerator/36.0)));
        distAccuracy += rollPercentage[i];
    }
    distAccuracy = distAccuracy / 11.0;
}




void Datapool::printResults() {
    cout << "Strategy chosen: " << strategyInt << endl;
    cout << "Number of rolls" << endl;
    for (int i = 2; i <= 12; i++) {
        cout << setprecision(5) << "[" << i << "]: " << numRolls[i] << " rolls, ";
    }
    cout << endl;
    cout << "Roll accuracy" << endl;
    for (int i = 2; i <= 12; i++) {
        cout << setprecision(5) << "[" << i << "]: "
             << rollPercentage[i] << "% acc, ";
    }
    cout << endl;

    cout << "Number of wins: " << numWins << ", Number of losses: " << numLosses << endl;
    cout << "Win percentage: " << winRatio * 100 << "%" << endl;
    cout << "House advantage: " << 50.0 - (winRatio*100) << "%" << endl;
    cout << "Dice roll distribution accuracy (DRDA) = " << distAccuracy << "%" << endl;

}