#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int numGames;

int startBettingRedBlack(int startingCash, int goalAmount, int wagerAmount){
    
    
    
    int currentCash = startingCash;
    // srand((unsigned int)time(nullptr));  
    while (currentCash!= 0 && currentCash < goalAmount){
        // clog << "currentCash is " << currentCash << endl;
        int myBet = rand() % 36 + 1;
        int actualRoll = rand() % 36;
        // clog << "myBet is " << myBet << endl;
        // clog << "actualRoll is " << actualRoll << endl;

        if (actualRoll == 0){
            currentCash -= wagerAmount;
        }
        else if ((myBet < 18 && actualRoll < 18) || (myBet > 18 && actualRoll > 18)){
            currentCash += wagerAmount;
            // clog << "myBet is " << myBet << endl;
            // clog << "actualRoll is " << actualRoll << endl;
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
        // clog << "This should be a win" << endl;
        return 1;
    }
}

int main(int argc, char ** argv){

    cout << "argc is " << argc << endl;
    cout << "*argv is " << *argv << endl;
    // cout << "**argv is " << **argv << endl;
    // cout << "&argv is " << &argv << endl;

    int strategyType = -1;
    cout << "Please enter a playstyle:" << endl;
    cout << "Enter 1 for Red & Black bets only (high odds, low risk,, 1-to-1 payout)" << endl;
    cout << "Enter 2 for one number bets only (low odds, high risk, 36-to-1 payout (BIG WIN))" << endl;
    if (argc < 1){
        cin >> strategyType;
    }
    cout << "strategyType is " << strategyType << endl;

    int sampleSize = 100000;
    int startingCash = 50;
    int wagerAmount = 10;
    int goalAmount = 100;

    // int allResults[sampleSize];
    int numWins = 0;
    int numLosses = 0;
    
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* using nano-seconds instead of seconds */
    srand((time_t)ts.tv_nsec);

    
    for (int i = 0; i < sampleSize; i++){

        int nextResult = startBettingRedBlack(startingCash, goalAmount, wagerAmount);
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
    cout << "Play style: " << strategyType << endl;
    cout << "Total number of sessions: " << sampleSize << endl;
    cout << "Total number of bets made: " << numGames << endl;
    cout << "Average number of games needed to reach a full win/loss: " << numGames/sampleSize << endl;
    cout << "Total number of wins: " << numWins << ". Total number of losses: " << numLosses << endl;
    double winPercentage = double(numWins) / double(sampleSize);
    cout << "Win percentage = " << winPercentage * 100 << "%" << endl;

    


    return 0;
}