#include "Dice.h"

int Dice::possibleRolls[] = {2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,10,10,10,11,11,12};

//int arraySize = sizeof(Dice::possibleRolls);

int Dice::roll(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    int arraySize = sizeof(Dice::possibleRolls)/sizeof(Dice::possibleRolls[0]);
    int diceRoll = possibleRolls[rand() % arraySize];
    return diceRoll;
}
