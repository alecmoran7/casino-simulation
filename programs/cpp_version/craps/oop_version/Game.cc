// Game.cc
#include "Game.h"
//    VARIABLES USED IN Game.h
// ------------------------------
//    int startingCash;
//    int goalCash;
//    enum betType {passLine, dontPass, fieldDouble, fieldTriple, anySeven, anyCraps, comeOnly, dontCome};
//    enum gameState {comeOut, activeGame};
//    betType strategy;
//    gameState currentGameState;
//    Dice dice;

using namespace std;

Game::Game(betType strategy, int startingCash, int goalCash) {
    this->strategy = strategy;
    this->startingCash = startingCash;
    this->goalCash = goalCash;
    numBets = 0;
}

Game::gameState getGameState() {
    return Game::currentGameState;
}

void setGameState(Game::gameState inputGameState) {
    Game::currentGameState = inputGameState;
};

bool rolledPass(int diceRoll) {
    if ((diceRoll == 7) || (diceRoll == 11)) {
        return true;
    } else return false;
}

bool rolledCraps(int diceRoll) {
    if ((diceRoll == 2) || (diceRoll == 3) || (diceRoll == 12)) {
        return true;
    } else return false;
}

int rollField(int diceRoll, int fieldMultiplier) {
    int pM = 0; // pm is payoutMultiplier
    switch (diceRoll) {
        case 2:
            pM = 2;
        case 3:
            pM = 1;
        case 4:
            pM = 1;
        case 5:
            pM = 0;
        case 6:
            pM = 0;
        case 7:
            pM = 0;
        case 8:
            pM = 0;
        case 9:
            pM = 1;
        case 10:
            pM = 1;
        case 11:
            pM = 1;
        case 12:
            fieldMultiplier == 2 ? pM = 2 : pM = 3;
    }
    return pM;
}

int playThePoint(int currentCash, int wagerAmount, int diceRoll, Game::betType strategy) {
    int fieldResult = 0;
    int thePoint = diceRoll;
    diceRoll = -1;
    while ((diceRoll != thePoint) || diceRoll != 7) {
        diceRoll = Game::dice.roll();
        bool rolledSeven = (diceRoll == 7) ? true : false;
        bool rolledThePoint = (diceRoll == thePoint) ? true : false;
        switch (strategy) {
            case Game::passLine:
                currentCash -= (rolledSeven) ? wagerAmount : 0;
                currentCash += (rolledThePoint) ? wagerAmount : 0;
                break;
            case Game::dontPass:
                if (diceRoll == 12) {
                    break;
                    // Don't pass bar on 12 returns the original bet back to the player, therefor nothing is added here
                } else {
                    currentCash += (rolledSeven) ? wagerAmount : 0;
                    currentCash -= (rolledThePoint) ? wagerAmount : 0;
                }
                break;
            case Game::fieldDouble:
                fieldResult = rollField(diceRoll, 2);
                if (fieldResult == 0) {
                    currentCash -= wagerAmount;
                } else {
                    currentCash += wagerAmount * fieldResult;
                }
                break;
            case Game::fieldTriple:
                fieldResult = rollField(diceRoll, 2);
                if (fieldResult == 0) {
                    currentCash -= wagerAmount;
                } else {
                    currentCash += wagerAmount * fieldResult;
                }
                break;
            case Game::anySeven:
                if (diceRoll == 7) {
                    currentCash += wagerAmount * 4;
                } else {
                    currentCash -= wagerAmount;
                }
                break;
            case Game::anyCraps:
                // Not implemented yet
                break;
            case Game::comeOnly:
                // Not implemented yet
                break;
            case Game::dontCome:
                // Not implemented yet
                break;
        }
    }
    return currentCash;
}


int playComeOut(int currentCash, int wagerAmount, int diceRoll, Game::betType strategy) {
    bool crapsRolled = rolledCraps(diceRoll);
    bool passRolled = rolledPass(diceRoll);
    int fieldResult = 0;
    switch (strategy) {
        case Game::passLine:
            currentCash -= (crapsRolled) ? wagerAmount : 0;
            currentCash += (passRolled) ? wagerAmount : 0;
            break;
        case Game::dontPass:
            if (diceRoll == 12) {
                // Don't pass bar on 12 returns the original bet back to the player, therefor nothing is added here
            } else {
                currentCash += (crapsRolled) ? wagerAmount : 0;
                currentCash -= (passRolled) ? wagerAmount : 0;
            }
            break;
        case Game::fieldDouble:
            fieldResult = rollField(diceRoll, 2);
            if (fieldResult == 0) {
                currentCash -= wagerAmount;
            } else {
                currentCash += wagerAmount * fieldResult;
            }
            break;
        case Game::fieldTriple:
            fieldResult = rollField(diceRoll, 2);
            if (fieldResult == 0) {
                currentCash -= wagerAmount;
            } else {
                currentCash += wagerAmount * fieldResult;
            }
            break;
        case Game::anySeven:
            if (diceRoll == 7) {
                currentCash += wagerAmount * 4;
            } else {
                currentCash -= wagerAmount;
            }
            break;
        case Game::anyCraps:
            // Not implemented yet
            break;
        case Game::comeOnly:
            // Not implemented yet
            break;
        case Game::dontCome:
            // Not implemented yet
            break;
    }
    return currentCash;
}

bool pointEstablished(int firstDiceRoll) {
    switch (firstDiceRoll) {
        case 2:
        case 3:
        case 12:
        case 7:
        case 11:
            return false;
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
            return true;
        default:
            exit(2);
    }

}

// Returns true if the player reaches their goal amount of winnings, Returns false if the player lost all their money
bool playCraps() {
    int currentCash = Game::startingCash;
    int goalAmount = Game::goalCash;
    int wagerAmount = Game::wagerAmount;
    setGameState(Game::comeOut);
    while (currentCash != 0 || currentCash < goalAmount) {
        int diceRoll = Game::dice.roll();
        currentCash = playComeOut(currentCash, wagerAmount, diceRoll, Game::strategy);
        if (pointEstablished(diceRoll)) {
            currentCash = playThePoint(currentCash, wagerAmount, diceRoll, Game::strategy);
        }
    }
    bool goalAmountAchieved = (currentCash == goalAmount) ? true : false;
    return goalAmountAchieved;
};