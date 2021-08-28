import random
import sys
from crapsBets import *

winLossStats = []
numGames = 0
diceRolls = [2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,10,10,10,11,11,12]
betOptions = ["field", "pass","dontpass"]
numPlayers = 1

def main():
    if len(sys.argv) > 1:
        betType = sys.argv[1]
    else:
        betType = input("Please enter a betType (options are field, pass, dontpass): ")
    if betType not in betOptions:
        while betType not in betOptions:
            betType = input("Please enter a betType (options are field, pass, dontpass): ")



    sampleSize = 10000
    numPlayers = sampleSize
    startingCash = 100
    wagerAmount = 25
    goalAmount = 200

    numWins = 0
    numLosses = 0

    for x in range(1,sampleSize + 1):
        startPlaying(x, startingCash, goalAmount, wagerAmount, betType)

    for i in winLossStats:
        if i == 0:
            numLosses = numLosses + 1
        else:
            numWins = numWins + 1

    print("")
    print("------------------------------------")
    print("Final Results (Craps):")
    print("Total number of simulated players: " + str(sampleSize))
    print("Total number of bets made: " + str(numGames))
    print("Average number of games needed to reach a complete or win/loss of money: " + str(numGames/sampleSize))
    print("Total number of wins: " + str(numWins) + ". Total number of losses: " + str(numLosses))
    winPercentage = numWins / sampleSize
    print("Win percentage = " + str(winPercentage * 100) + "%")
    print("House advantage = " + str(50 - (winPercentage * 100)) + "%")


def evalBet(resultNum, currentCash, comeoutRoll, betType, wagerAmount, thePoint):
    if betType == "field":
        return int(rollField(resultNum, currentCash, comeoutRoll, wagerAmount))
    elif betType == "pass":
        return int(passLine(resultNum, currentCash, comeoutRoll, wagerAmount, thePoint))
    elif betType == "dontpass":
        return int(dontPassLine(resultNum, currentCash, comeoutRoll, wagerAmount, thePoint))


    else:
        print("betType is actually: " + str(betType))
        exit("well thats not good")

def startPlaying(setNumber, startingCash, goalAmount, wagerAmount, betType):
    global numGames
    currentCash = startingCash
    comeoutRoll = True
    thePoint = 0
#     print(type(currentCash))
#     print(type(goalAmount))
#     exit()
    while currentCash != 0 and currentCash < goalAmount:
        if currentCash < 0:
            exit("CurrentCash somehow got to " + str(currentCash))
        resultNum = random.choice(diceRolls)
#         print("Player #" + str(setNumber) +" has $" + str(currentCash) + " and just rolled a " + str(resultNum))
        currentCash = evalBet(resultNum, currentCash, comeoutRoll, betType, wagerAmount, thePoint)
        if comeoutRoll == True:
#             print("Come out roll was a " + str(resultNum))
            thePoint = resultNum
            if resultNum == 2 or resultNum == 3 or resultNum == 12 or resultNum == 7 or resultNum == 11:
                comeoutRoll = True # A craps or lucky 7/11 was rolled
            else:
                comeoutRoll = False

        else:
#             print("Additional roll: " + str(resultNum) + ", Come roll is a " + str(thePoint))
            if resultNum == thePoint or resultNum == 7:
#                 print("Successfully rolled the come (or seven)")
                comeoutRoll = True
            else:
                comeoutRoll = False
        numGames += 1
    if currentCash >= goalAmount:
        winLossStats.append(1)
    else:
        winLossStats.append(0)
    if (setNumber % 100 == 0):
        print("Working... (" + str((setNumber/numPlayers) / 100)+ "%)")

if __name__ == "__main__":
    main()