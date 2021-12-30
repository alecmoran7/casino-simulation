#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int numGames;
enum Strategy {passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome};
int allRolls[] = {2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,10,10,10,11,11,12};
int crapsRolls[] = {2,3,12}
int arraySize = sizeof(allRolls)/sizeof(allRolls[0]);


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

// int redSquaresArray[] = {1,3,5,7,9,12,14,16,18,21,23,25,27,28,30,32,34,36};
// int blackSquaresArray[] = {2,4,6,8,10,11,13,15,17,19,20,22,24,26,29,31,33,35};
// int arraySize = sizeof(redSquaresArray)/sizeof(redSquaresArray[0]);
// vector<int> redSquares = intArrayToVector(redSquaresArray, arraySize);
// vector<int> blackSquares = intArrayToVector(blackSquaresArray, arraySize);

int checkWinCondition(int currentCash, int wagerAmount, int playerRoll, int actualRoll, Strategy betType){
/*
    switch (betType){
        case passLine:
            if (){}
            else if (){}
            else {}
            break;

        case dontPass:
            if (){}
            else if (){}
            else {}
            break;

        case fieldDouble:
            if (){}
            else if (){}
            else {}
            break;

        case fieldTriple:
            if (){}
            else if (){}
            else {}
            break;
        
        case anySeven:
            if (){}
            else if (){}
            else {}
            break;

        case anyCraps:
            if (){}
            else if (){}
            else {}
            break;

        case comeOnly:
            if (){}
            else if (){}
            else {}
            break;

        case dontCome:
            if (){}
            else if (){}
            else {}
            break;

        default:
            cerr << "Error invalid strategy type provided: " << betType << endl;
            exit(1);
            break;
    };
*/
    return currentCash;
}

int playUntilCome(int comeoutRoll, int wagerAmount, Strategy betType){
    int nextRoll = -1;
    gameIsActive = true;
    while (gameIsActive){
        nextRoll = allRolls[rand() % arraySize];
    }
}

bool startBetting(int startingCash, int goalAmount, int wagerAmount, Strategy betType){
    int currentCash = startingCash;
    currentCash += 0;
    int actualRoll = allRolls[rand() % arraySize];
    clog << "actualRoll is " << actualRoll << endl;
    while (currentCash!= 0 && currentCash < goalAmount){
        bool gameOn = false;
        int comeoutRoll = allRolls[rand() % arraySize];
        if (comeoutRoll == 7 || comeoutRoll == 11){
            currentCash = evalCome(wagerAmount,betType);
        }
        else if (comeoutRoll == 2 || comeoutRoll == 3){
            currentCash == evalCraps(wagerAmount,betType)
        }
        else if (comeoutRoll == 12){
            currentCash == evalBar(wagerAmount, betType)
        }
        else if (comeoutRoll != 2 && comeoutRoll != 3 && comeoutRoll != 7 && comeoutRoll !=11 && comeoutRoll != 12){
            currentCash = playUntilCome(comeoutRoll, wagerAmount,betType);
        }
        numGames += 1;

    //     int actualRoll = rand() % 36;
    //     currentCash = checkWinCondition(currentCash, wagerAmount, myBet, actualRoll, betType);
    }    
    if (currentCash == 0){
        return false;
    }
    else {
        return true;
    }
    return false;
}

int main(int argc, char* argv[]){
    
    int strategyType = -1;

    // If no betting style is used in the program parameters (./rouletteSim [#]), ask them to input one
    if (argc < 2){
        cout << "Please enter a playstyle:" << endl;
        cout << "Enter 0 for pass line" << endl;
        cout << "Enter 1 for don't pass line" << endl;
        cout << "Enter 2 for field play bets (double on 2, win on 3,4,9,10,11, double on twelve" << endl;
        cout << "Enter 3 for field play bets (double on 2, win on 3,4,9,10,11, triple on twelve" << endl;
        cout << "Enter 4 for any seven" << endl;
        cout << "Enter 5 for any craps" << endl;
        cout << "Enter 6 for come (after game is on)" << endl;
        cout << "Enter 7 for don't come (after game is on)" << endl;
        cin >> strategyType;
    }
    else {
        strategyType = stoi(argv[1]);
    }

    int sampleSize = 10000;
    int startingCash = 100;
    int wagerAmount = 25;
    int goalAmount = 200;
    string playStyle = "";
    Strategy betType;

    // Set the betting parameters based on what strategy the user has selected
    switch (strategyType){
        case 0:
            betType = passLine;
            playStyle = "Red and black bets only";
            break;
        case 1:
            betType = dontPass;
            playStyle = "Even and Odd bets only";
            break;
        case 2:
            betType = fieldDouble;
            playStyle = "Upper and lower half only";
            break;
        case 3:
            betType = fieldTriple;
            playStyle = "Upper and lower half only";
            break;
        case 4:
            betType = anySeven;
            playStyle = "[1-12], [13-24], and [25-36] bets only";
            break;
        case 5:
            betType = anyCraps;
            playStyle = "One number bets only";
            break;
        case 6:
            betType = comeOnly;
            playStyle = "2:1 row bets only";
            break;
        case 7:
            betType = dontCome;
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