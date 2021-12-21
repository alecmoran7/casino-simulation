#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int numGames;

int startBettingRedBlack(int startingCash, int goalAmount, int wagerAmount){   
     
    int currentCash = startingCash;
    while (currentCash!= 0 && currentCash < goalAmount){
        int myBet = rand() % 36 + 1;
        int actualRoll = rand() % 36;
        if (actualRoll == 0){
            currentCash -= wagerAmount;
        }
        else if ((myBet < 18 && actualRoll < 18) || (myBet > 18 && actualRoll > 18)){
            currentCash += wagerAmount;
        }
        else if ((myBet < 18 && actualRoll > 18) || (myBet > 18 && actualRoll < 18)){
            currentCash -= wagerAmount;
        }
        numGames += 1;
    }
    if (currentCash == 0){
        return 0;
    }
    else {
        return 1;
    }
}

int startBettingOneNum(int startingCash, int goalAmount, int wagerAmount){
    int currentCash = startingCash;
    while (currentCash!= 0 && currentCash < goalAmount){
        int myBet = rand() % 36;
        int actualRoll = rand() % 36;
        if (actualRoll == myBet){
            currentCash += wagerAmount * 36;
        }
        else {
            currentCash -= wagerAmount;
        }
        numGames += 1;
    }    
    if (currentCash == 0){
        return 0;
    }
    else {
        // clog << "This should be a win" << endl;
        return 1;
    }
}

int main(int argc, char ** argv){

    cout << "argc is " << argc << endl;
    cout << "*argv is " << *argv << endl;
    // cout << "**argv is " << **argv << endl;
    // cout << "&argv is " << &argv << endl;

    char strategyType = -1;
    if (argc != 2){
        cout << "Please enter a playstyle:" << endl;
        cout << "Enter 1 for Red & Black bets only (high odds, low risk,, 1-to-1 payout)" << endl;
        cout << "Enter 2 for one number bets only (low odds, high risk, 36-to-1 payout (BIG WIN))" << endl;
        cin >> strategyType;
    }
    else {
        strategyType = *argv[1] - '0';
    }
    cout << "strategyType is " << strategyType << endl;

    int sampleSize = 100000;
    int startingCash = 50;
    int wagerAmount = 10;
    int goalAmount = 100;
    string playStyle = "";
    
    switch (strategyType){
        case 0:
            sampleSize = 1000000000;
            startingCash = 50;
            wagerAmount = 10;
            goalAmount = 100;
            playStyle = "Red and black bets only";
            break;
        case 1:
            sampleSize = 1000000000;
            startingCash = 100;
            wagerAmount = 5;
            goalAmount = 200;
            playStyle = "One number bets only";
            break;
    }

    // int allResults[sampleSize];
    int numWins = 0;
    int numLosses = 0;
    
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* using nano-seconds instead of seconds */
    srand((time_t)ts.tv_nsec);
    int nextResult = 0;
    for (int i = 0; i < sampleSize; i++){
        switch (strategyType){
            case 0:
                nextResult = startBettingRedBlack(startingCash, goalAmount, wagerAmount);
                break;
            case 1:
                nextResult = startBettingOneNum(startingCash, goalAmount, wagerAmount);
                break;
            default:
                cerr << "Error invalid strategy type provided -> " << strategyType << ", valid options are 1 or 2." << endl;
                exit(1);
        }
        switch(nextResult){
            case 0:
                ++numLosses;
                break;
            case 1:
                ++numWins;
                // clog << "got a win" << endl;
                break;
            default:
                clog << "ERROR other option detected -> " << nextResult << endl;
                exit(1);
        }
    }


    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Final Results:" << endl;
    cout << "Play style: " << playStyle << endl;
    cout << "Total number of sessions: " << sampleSize << endl;
    cout << "Total number of bets made: " << numGames << endl;
    cout << "Average number of games needed to reach a full win/loss: " << numGames/sampleSize << endl;
    cout << "Total number of wins: " << numWins << ". Total number of losses: " << numLosses << endl;
    double winPercentage = double(numWins) / double(sampleSize);
    cout << "Win percentage = " << winPercentage * 100 << "%" << endl;

    


    return 0;
}