#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int numGames;
enum Strategy {redBlack, evenOdd, twoHalves, threeSplit, oneNumber, threeRows, zeroOnly};

bool vectorContains( vector<int> inputVector, int inputValue){
    return (find(inputVector.begin(), inputVector.end(), inputValue) != inputVector.end()) ? true : false;
}

vector<int> intArrayToVector(int inputArray[], int arraySize){
    vector<int> outputVector;
    for(int i = 0; i < arraySize; i++){
        outputVector.insert(outputVector.begin() + i, inputArray[i]);
    }
    return outputVector;
}

int redSquaresArray[] = {1,3,5,7,9,12,14,16,18,21,23,25,27,28,30,32,34,36};
int blackSquaresArray[] = {2,4,6,8,10,11,13,15,17,19,20,22,24,26,29,31,33,35};
int arraySize = sizeof(redSquaresArray)/sizeof(redSquaresArray[0]);
vector<int> redSquares = intArrayToVector(redSquaresArray, arraySize);
vector<int> blackSquares = intArrayToVector(blackSquaresArray, arraySize);

int checkWinCondition(int currentCash, int wagerAmount, int playerRoll, int actualRoll, Strategy betType){
    bool rf1, rf2, bf1, bf2 = false;;
    switch (betType){
        case redBlack:
            for (int i = 0; i < arraySize; i++){
                if (redSquaresArray[i] == actualRoll){
                    rf1 = true;
                    bf1 = false;
                }
                if (redSquaresArray[i] == playerRoll){
                    rf2 = true;
                    bf2 = false;
                }
                if (blackSquaresArray[i] == actualRoll){
                    bf1 = true;
                    rf1 = false;
                }
                if (blackSquaresArray[i] == playerRoll){
                    bf2 = true;
                    rf2 = false;
                }
            }

            if (actualRoll == 0){
                currentCash -= wagerAmount;
            }
            else if ((rf1 && rf2) || (bf1 && bf2)){
                currentCash += wagerAmount;
            }
            else {
                currentCash -= wagerAmount;
            }
            break;

        case evenOdd:
            if (actualRoll == 0){
                currentCash -= wagerAmount;
            }
            else if ((actualRoll % 2 == 0 && playerRoll % 2 == 0) || (actualRoll % 2 == 1 && playerRoll % 2 == 1)){
                currentCash += wagerAmount;
            }
            else {
                currentCash -= wagerAmount;
            }
            break;

        case twoHalves:
            if (actualRoll == 0){
                currentCash -= wagerAmount;
            }
            else if ((playerRoll <= 18 && actualRoll <= 18) || (playerRoll > 18 && actualRoll > 18)){
                currentCash += wagerAmount;
            }
            else{
                currentCash -= wagerAmount;
            }
            break;
        
        case threeSplit:
            if (actualRoll == 0){
                currentCash -= wagerAmount;
            }
            else if ((actualRoll >= 1 && actualRoll <= 12 && playerRoll >= 1 && playerRoll <= 12) || (actualRoll >= 13 && actualRoll <= 24 && playerRoll >= 13 && playerRoll <= 24) || (actualRoll >= 25 && actualRoll <= 36 && playerRoll >= 25 && playerRoll <= 36)){
                currentCash += wagerAmount * 2;
            }
            else {
                currentCash -= wagerAmount;
            }
            break;

        case oneNumber:
            if (actualRoll == 0){
                currentCash -= wagerAmount;
            }
            else if (playerRoll == actualRoll){
                currentCash += wagerAmount * 36;
            }
            else {
                currentCash -= wagerAmount;
            }
            break;

        case threeRows:
            if (actualRoll == 0){
                currentCash -= wagerAmount;
            }
            else if (actualRoll % 3 == playerRoll){
                currentCash += wagerAmount * 2;
            }
            else {
                currentCash -= wagerAmount;
            }
            break;

        case zeroOnly:
            if (actualRoll == 0){
                currentCash += wagerAmount * 36;
            }
            else {
                currentCash -= wagerAmount;
            }
            break;

        default:
            cerr << "Error invalid strategy type provided: " << betType << endl;
            exit(1);
            break;
    };

    return currentCash;
}

bool startBetting(int startingCash, int goalAmount, int wagerAmount, Strategy betType){
    int currentCash = startingCash;
    while (currentCash!= 0 && currentCash < goalAmount){
        int myBet = -1;
        switch (betType){
            case redBlack:
            case evenOdd:
            case twoHalves:
            case threeSplit:
            case oneNumber:
                myBet = 1 + rand() % 36;
                break;
            case threeRows: 
                myBet = rand() % 3;
                break;
            case zeroOnly:
                myBet = 0;
                break;
            default:
                cerr << "Error unexpected betType found -> " << betType << endl;
                exit(1);
        }
        int actualRoll = rand() % 36;
        currentCash = checkWinCondition(currentCash, wagerAmount, myBet, actualRoll, betType);
        numGames += 1;
    }    
    if (currentCash == 0){
        return false;
    }
    else {
        return true;
    }
}

int main(int argc, char* argv[]){
    
    int strategyType = -1;

    // If no betting style is used in the program parameters (./rouletteSim [#]), ask them to input one
    if (argc < 2){
        cout << "Please enter a playstyle:" << endl;
        cout << "Enter 0 for Red & Black bets only (high odds, low risk,, 1-to-1 payout)" << endl;
        cout << "Enter 1 for Even and Odd bets only [zero does not count as an even number] (high odds, low risk, 1-to-1 payout)" << endl;
        cout << "Enter 2 for Upper and Lower half bets only [1-18] or [19-36] (high odds, low risk, 1-to-1 payout)" << endl;
        cout << "Enter 3 for three-grouped bets only [1-12], [13-24], or [25-36] (medium odds, medium risk, 2-to-1 payout)" << endl;
        cout << "Enter 4 for one number bets only [any single number 0-36] (low odds, high risk, 36-to-1 payout (BIG WIN))" << endl;
        cout << "Enter 5 for 2:1 row bets only [rows 1, 2, or 3] (medium odds, medium risk, 2-to-1 payout)" << endl;
        cout << "Enter 6 for betting on zero only (low odds, high risk, 36-to-1 payout (BIG WIN))" << endl;
        cin >> strategyType;
    }
    else {
        strategyType = stoi(argv[1]);
    }

    int sampleSize = 100000;
    int startingCash;
    int wagerAmount;
    int goalAmount;
    string playStyle = "";
    Strategy betType;

    // Set the betting parameters based on what strategy the user has selected
    switch (strategyType){
        case 0:
            betType = redBlack;
            startingCash = 50;
            wagerAmount = 25;
            goalAmount = 100;
            playStyle = "Red and black bets only";
            break;
        case 1:
            betType = evenOdd;
            startingCash = 50;
            wagerAmount = 25;
            goalAmount = 100;
            playStyle = "Even and Odd bets only";
            break;
        case 2:
            betType = twoHalves;
            startingCash = 100;
            wagerAmount = 50;
            goalAmount = 200;
            playStyle = "Upper and lower half only";
            break;
        case 3:
            betType = threeSplit;
            startingCash = 200;
            wagerAmount = 50;
            goalAmount = 400;
            playStyle = "[1-12], [13-24], and [25-36] bets only";
            break;
        case 4:
            betType = oneNumber;
            startingCash = 360;
            wagerAmount = 10;
            goalAmount = 720;
            playStyle = "One number bets only";
            break;
        case 5:
            betType = threeRows;
            startingCash = 200;
            wagerAmount = 50;
            goalAmount = 400;
            playStyle = "2:1 row bets only";
            break;
        case 6:
            betType = zeroOnly;
            startingCash = 360;
            wagerAmount = 10;
            goalAmount = 720;
            playStyle = "Single zero bets only";
            break;
        default:
            cerr << "Error invalid betType found --> " << strategyType << ", options are [0-6]. " << endl;
            exit(1);
    }

    if (argc == 3){
        int goalMultiplier = atoi(argv[2]);
        goalAmount = startingCash * goalMultiplier;
    }

    if (argc == 4){
        sampleSize = atoi(argv[3]);
        clog << "sampleSize is " << sampleSize << endl;
    }

    int numWins = 0;
    int numLosses = 0;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    // Generating a new random value every nano-second instead of every second
    srand((time_t)ts.tv_nsec);

    bool nextResult;
    for (int i = 0; i < sampleSize; i++){
        nextResult = startBetting(startingCash, goalAmount, wagerAmount, betType);
        if (nextResult) {
            ++numWins;
        }
        else {
            ++numLosses;
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
    cout << "House advantage = " << 50 - (winPercentage * 100) << "%" << endl;

    return 0;
}