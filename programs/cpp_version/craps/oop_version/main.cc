//
// Created by Alec Moran on 12/31/21.
//
#include <iostream>
#include "Datapool.h"

using namespace std;

int main(int argc, char *argv[]) {

    // If no betting style is used in the program parameters (./rouletteSim [#]), ask them to input one
    if (argc < 4) {
        cerr
                << "Program format is as follows $ ./main [# of players (integer)] [strategy # (integer)] [starting dollar amount (integer)] [minimum winning ratio (Double, ex. 2 for doubling money)]"
                << endl;
        cerr << "Strategy numbers are as follows:" << endl;
        cerr << " 0 for pass line" << endl;
        cerr << " 1 for don't pass line" << endl;
        cerr << " 2 for field play bets (double on 2, win on 3,4,9,10,11, double on twelve" << endl;
        cerr << " 3 for field play bets (double on 2, win on 3,4,9,10,11, triple on twelve" << endl;
        cerr << " 4 for any seven" << endl;
        cerr << " 5 for any craps" << endl;
        cerr << " 6 for come (after game is on)" << endl;
        cerr << " 7 for don't come (after game is on)" << endl;
        exit(1);
    }

    // Default parameter values
    int numSamples = 10000;
    int strategyInt = 0;
    int startingCash = 100;
    double goalMultiplier = 2.0;
    try {
        numSamples = stoi(argv[1]);
        strategyInt = stoi(argv[2]);
        startingCash = atoi(argv[3]);
        goalMultiplier = stod(argv[4]);

    }
    catch (string E) {
        cerr << "Exception, invalid input specified -> " << E << endl;
    }
    Datapool dataPool = Datapool(numSamples, startingCash, goalMultiplier, strategyInt);
    dataPool.gatherPlayerData();
    dataPool.analyzeDiceData();
    dataPool.printResults();
    return 0;

}