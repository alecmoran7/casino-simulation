#ifndef DICE_H
#define DICE_H

#include <stdio.h>

using namespace std;

class Dice {
public:
    int possibleRolls[36] = {2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 12};
    Dice();
    int roll();
};

#endif