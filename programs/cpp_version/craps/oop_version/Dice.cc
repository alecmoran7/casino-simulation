#include "Dice.h"
int roll(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    int arraySize = sizeof(possibleRolls)/sizeof(possibleRolls[0]);
    int diceRoll = allRolls[rand() % arraySize];
    return diceRoll;
}
