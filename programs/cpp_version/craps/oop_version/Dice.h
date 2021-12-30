#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Dice {
    private:
        int possibleRolls[];
    public:
        int roll();
}