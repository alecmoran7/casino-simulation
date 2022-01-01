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
//    gameState currentGameState;
//    Dice dice;

#include <iostream>
using namespace std;

Game::Game(){
    Game(0, 100, 200);
}

Game::Game(int strategyInt, int startAmount, int goalAmount) {
    this->startingCash = startAmount;
    this->goalCash = goalAmount;
    this->numBets = 0;
    this->wagerAmount = (int)((goalAmount - startAmount)/2);
    // Set the betting parameters based on what strategy the user has selected
    switch (strategyInt) {
        case 0:
            this->strategy = passLine;
            break;
        case 1:
            this->strategy = dontPass;
            break;
        case 2:
            this->strategy = fieldDouble;
            break;
        case 3:
            this->strategy = fieldTriple;
            break;
        case 4:
            this->strategy = anySeven;
            break;
        case 5:
            this->strategy = anyCraps;
            break;
        case 6:
            this->strategy = comeOnly;
            break;
        case 7:
            this->strategy = dontCome;
            break;
        default:
            exit(2);
    }
//    clog << "Game finished initializing" << endl;
}

Game::gameState Game::getGameState() {
    return Game::currentGameState;
}

void Game::setGameState(Game::gameState inputGameState) {
    Game::currentGameState = inputGameState;
}

bool Game::rolledPass(int diceRoll) {
    if ((diceRoll == 7) || (diceRoll == 11)) {
        return true;
    } else return false;
}

bool Game::rolledCraps(int diceRoll) {
    if ((diceRoll == 2) || (diceRoll == 3) || (diceRoll == 12)) {
        return true;
    } else return false;
}

int Game::rollField(int diceRoll, int fieldMultiplier) {
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

int Game::playThePoint(int currentCash, int wagerAmount, int diceRoll, Game::betType strategy) {
    int fieldResult = 0;
    int thePoint = diceRoll;
    diceRoll = -1;
    while ((diceRoll != thePoint) && diceRoll != 7) {
//        clog << "ptp1" << endl;
        diceRoll = dice.roll();
//        clog << "diceRoll is " << diceRoll << endl;
//        clog << "ptp2" << endl;
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


int Game::playComeOut(int currentCash, int wagerAmount, int diceRoll, Game::betType strategy) {
//    clog << "parameter wagerAmount is: " << wagerAmount << endl;
    bool crapsRolled = rolledCraps(diceRoll);
    bool passRolled = rolledPass(diceRoll);
//    clog << "crapsRolled: " << crapsRolled << endl;
//    clog << "passRolled: " << passRolled << endl;
    int fieldResult = 0;
    switch (strategy) {
        case Game::passLine:
//            clog << "currentCash before alter: " << currentCash << endl;
//            clog << "wagerAmount is: " << wagerAmount << endl;

            currentCash -= (crapsRolled) ? wagerAmount : 0;
            currentCash += (passRolled) ? wagerAmount : 0;
//            clog << "currentCash after alter: " << currentCash << endl;
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

bool Game::pointEstablished(int firstDiceRoll) {
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
bool Game::playCraps() {
    int currentCash = this->startingCash;
    int goalAmount = this->goalCash;
    int wagerAmount = this->wagerAmount;
//    clog << "this->wagerAmount is: " << this->wagerAmount << endl;

    setGameState(this->comeOut);
    while (currentCash > 0 && currentCash < goalAmount) {
//        clog << "currentCash is " << currentCash  << " goalAmount is " << goalAmount << endl;
        int diceRoll = dice.roll();
//        clog << "diceRoll is " << diceRoll << endl;
        currentCash = playComeOut(currentCash, wagerAmount, diceRoll, strategy);
//        clog << "currentCash after comeout is " << currentCash << endl;
        if (pointEstablished(diceRoll)) {
//            clog << "pc4" << endl;
            currentCash = playThePoint(currentCash, wagerAmount, diceRoll, strategy);
//            clog << "pc5" << endl;
        }
    }
    bool goalAmountAchieved = (currentCash == goalAmount) ? true : false;
    return goalAmountAchieved;
};