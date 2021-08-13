import random
import sys

winLossStats = []
numGames = 0
diceRolls = [2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,10,10,10,11,11,12]

def main():

    sampleSize = 10000
    startingCash = 100
    wagerAmount = 10
    goalAmount = 200

    numWins = 0
    numLosses = 0

    for x in range(1,sampleSize + 1):
        startPlaying(x, startingCash, goalAmount, wagerAmount)

    for i in winLossStats:
        if i == 0:
            numLosses = numLosses + 1
        else:
            numWins = numWins + 1

    print("")
    print("------------------------------------")
    print("Final Results (Craps):")
    print("Total number of sessions: " + str(sampleSize))
    print("Total number of bets made: " + str(numGames))
    print("Average number of games needed to reach a full win/loss: " + str(numGames/sampleSize))
    print("Total number of wins: " + str(numWins) + ". Total number of losses: " + str(numLosses))
    winPercentage = numWins / sampleSize
    print("Win percentage = " + str(winPercentage * 100) + "%")

def startPlaying(setNumber, startingCash, goalAmount, wagerAmount):
    global numGames
    currentCash = startingCash
    comeoutRoll = True
    firstRoll = 0
    while currentCash != 0 and currentCash < goalAmount:
        resultNum = random.choice(diceRolls)
        print("Player #" + str(setNumber) +" has $" + str(currentCash) + " and just rolled a " + str(resultNum));
        if comeoutRoll == True:
            print("Come out roll was a " + str(resultNum))
            firstRoll = resultNum
            if resultNum == 2 or resultNum == 3:
                print("Lucky 2/3 on come out roll")
                currentCash += wagerAmount
                comeoutRoll = True
            elif resultNum == 7 or resultNum == 11:
                print("7/11 Craps")
                currentCash -= wagerAmount
            elif resultNum == 12:
                print("12 bar")
                comeoutRoll = True
            else:
                comeoutRoll = False
        else:
            print("Additional roll: " + str(resultNum) + ", Trying to hit 7 and avoid " + str(firstRoll))
            if resultNum == firstRoll:
                print("Rolled the come")
                currentCash -= wagerAmount
                comeoutRoll = True
            elif resultNum == 7:
                print("Rolled a lucky seven")
                currentCash += wagerAmount
                comeoutRoll = True
            else:
                comeoutRoll = False
        numGames += 1
    #print("result of game #" + str(setNumber) + " remaining cash: " + str(currentCash))
    if currentCash >= goalAmount:
        print("Player #" + str(setNumber) + " was a winner! They ended up with $" + str(currentCash) + " in their pocket!")
        winLossStats.append(1)
    else:
        print("Player #" + str(setNumber) + " unfortunately lost all their cash.")
        winLossStats.append(0)

if __name__ == "__main__":
    main()