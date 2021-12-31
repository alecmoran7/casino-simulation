#ifndef DICE_H
#define DICE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Dice {
public:
    static int possibleRolls[];

    Dice();

    int roll();
};

#endif