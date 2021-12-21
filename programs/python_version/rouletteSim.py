import random
import sys

winLossStats = []
numGames = 0

def main():
    
    if len(sys.argv) > 1:
        inputStrategy = str(sys.argv[1])
    else:
        print("Please enter a playstyle:")
        print("Enter 1 for Red & Black bets only (high odds, low risk,, 1-to-1 payout)")
        print("Enter 2 for one number bets only (low odds, high risk, 36-to-1 payout (BIG WIN))") 
        inputStrategy = input()
    strategyType = "Red and Black bets only" if inputStrategy == "1" else ""
    strategyType = "Single number bets only" if inputStrategy == "2" else ""

    if inputStrategy != "1" and inputStrategy != "2":
        print("Input was not one of the valid options -> " + str(inputStrategy)  + ", please restart the program and try again.")
        exit()

    sampleSize = 100000
    startingCash = 50
    wagerAmount = 10
    goalAmount = 100

    if inputStrategy == "2": #Have at least 50 bets before running out of money, since the chances of winning are 1/37 in one-number only bets.
        startingCash = 100
        wagerAmount = 2
        goalAmount = 200

    numWins = 0
    numLosses = 0

    if inputStrategy == "1": #Play red or blacks only
        for x in range(1,sampleSize + 1):
            startBettingRedBlack(x, startingCash, goalAmount, wagerAmount)

    if inputStrategy == "2": #Play one number bets only
        for x in range(1,sampleSize + 1):
            startBettingOneNum(x, startingCash, goalAmount, wagerAmount)

    for i in winLossStats:
        if i == 0:
            numLosses = numLosses + 1
        else:
            numWins = numWins + 1

    print("")
    print("------------------------------------")
    print("Final Results:")
    print("Play style: " + str(strategyType))
    print("Total number of sessions: " + str(sampleSize))
    print("Total number of bets made: " + str(numGames))
    print("Average number of games needed to reach a full win/loss: " + str(numGames/sampleSize))
    print("Total number of wins: " + str(numWins) + ". Total number of losses: " + str(numLosses))
    winPercentage = numWins / sampleSize
    print("Win percentage = " + str(winPercentage * 100) + "%")

def startBettingOneNum(setNumber, startingCash, goalAmount, wagerAmount):
    global numGames
    currentCash = startingCash
    while currentCash != 0 and currentCash < goalAmount:
        myBet = random.randint(0,36)
        resultNum = random.randint(0,36)
        if myBet == resultNum:
            currentCash += wagerAmount*36
        else:
            currentCash -= wagerAmount
        numGames += 1
    if currentCash >= goalAmount:
        winLossStats.append(1)
    else:
        winLossStats.append(0)



def startBettingRedBlack(setNumber, startingCash, goalAmount, wagerAmount):
    global numGames
    currentCash = startingCash
    while currentCash != 0 and currentCash < goalAmount:
        myBet = random.randint(1,36)
        resultNum = random.randint(0,36)
        if resultNum == 0:
            currentCash -= wagerAmount
        elif myBet <= 18 and resultNum <= 18 or myBet > 18 and resultNum > 18:
            currentCash += wagerAmount
        else:
            currentCash -= wagerAmount
        numGames += 1
    if currentCash == goalAmount:
        winLossStats.append(1)
    else:
        winLossStats.append(0)


if __name__ == "__main__":
    main()