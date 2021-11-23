import random
import sys
import threading
from crapsBets import *

sampleSize = 10000
numPlayers = sampleSize
startingCash = 100
wagerAmount = 25
goalAmount = 200
numWins = 0
numLosses = 0

class myThread (threading.Thread):
   def __init__(self, threadID, betType):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.betType = betType
      self.sampleSize = sampleSize
   def run(self):
      global startingCash
      global goalAmount
      global sampleSize
      global wagerAmount
      print("Starting Thread #" + str(self.threadID))
      for x in range(1,sampleSize + 1):
          startPlaying(x, startingCash, goalAmount, wagerAmount, self.betType, self.threadID)

winLossStats = []
numGames = 0
diceRolls = [2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,10,10,10,11,11,12]
betOptions = ["field", "pass","dontpass"]

def main():
    global sampleSize, numPlayers, startingCash, wagerAmount, goalAmount, numWins, numLosses, winLossStats, numGames, diceRolls, betOptions
    startingSample = sampleSize

    betType = ""
    numThreads = 6
    if len(sys.argv) > 2:
        numThreads = int(sys.argv[2])
    if len(sys.argv) > 1:
        betType = sys.argv[1]
    else:
        betType = input("Please enter a betType (options are field, pass, dontpass): ")
    if betType not in betOptions:
        while betType not in betOptions:
            betType = input("Please enter a betType (options are field, pass, dontpass): ")

    allThreads = []
    # Create new threads
    for i in range(numThreads):
        newThread = myThread (i, betType)
        allThreads.append(newThread)
        newThread.start()

    numThreads = 0
    for t in allThreads:
        numThreads = numThreads + 1
        print("Thread " + str(t.threadID) + " is waiting")
        t.join()
        print("Thread " + str(t.threadID) + " has finished")
    print("All threads have finished")

    sampleSize = sampleSize * numThreads

    for i in winLossStats:
        if i == 0:
            numLosses = numLosses + 1
        else:
            numWins = numWins + 1

    print("")
    print("------------------------------------")
    print("Final Results (Craps): " + str(betType) + " bets only.")
    print("Total number of simulated players: " + str(sampleSize))
    print("Starting money: $ " + str(startingCash) + " | Wager Amount: $ " + str(wagerAmount))
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

def startPlaying(setNumber, startingCash, goalAmount, wagerAmount, betType, threadID):
    global numGames, numPlayers
    currentCash = startingCash
    comeoutRoll = True
    thePoint = 0
    while currentCash != 0 and currentCash < goalAmount:
        if currentCash < 0:
            exit("CurrentCash somehow got to " + str(currentCash))
        resultNum = random.choice(diceRolls)
        currentCash = evalBet(resultNum, currentCash, comeoutRoll, betType, wagerAmount, thePoint)
        if comeoutRoll == True:
            thePoint = resultNum
            if resultNum == 2 or resultNum == 3 or resultNum == 12 or resultNum == 7 or resultNum == 11:
                comeoutRoll = True # A craps or lucky 7/11 was rolled
            else:
                comeoutRoll = False
        else:
            if resultNum == thePoint or resultNum == 7:
                comeoutRoll = True
            else:
                comeoutRoll = False
        numGames += 1
    if currentCash >= goalAmount:
        winLossStats.append(1)
    else:
        winLossStats.append(0)
    if (setNumber % (sampleSize*(0.1)) == 0):
        print("Thread " + str(threadID) + " Working... (" + str((setNumber * 100) / sampleSize)+ "%)")

if __name__ == "__main__":
    main()