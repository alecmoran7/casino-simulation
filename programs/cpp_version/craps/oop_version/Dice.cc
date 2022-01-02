#include "Dice.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>


//int arraySize = sizeof(Dice::possibleRolls);
Dice::Dice(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
}

int Dice::roll(){
    int arraySize = sizeof(possibleRolls)/sizeof(possibleRolls[0]);
//    int randResult = rand() ;
//    clog << "randResult is " << randResult << endl;
//    clog << "arraySize is " << arraySize << endl;
    int diceRoll = possibleRolls[rand() % arraySize];
    allRolls.push_back(diceRoll);
//    clog << "@ diceRoll is " << diceRoll << endl;
    return diceRoll;
}
