#include "Dice.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <algorithm>

Dice::Dice(){
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	srand((time_t)ts.tv_nsec);
}

int Dice::roll(){
	shuffle(possibleRolls.begin(), possibleRolls.end(), default_random_engine(rand()));
	int diceRoll = possibleRolls[rand() % 36];
	allRolls.push_back(diceRoll);
	return diceRoll;
}
