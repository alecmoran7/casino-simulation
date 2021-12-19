#crapsBets.py
def rollField(resultNum, currentCash, comeoutRoll, wagerAmount):
    if resultNum == 2:
        currentCash += wagerAmount*2
    if resultNum == 12:
       currentCash += wagerAmount*3
    if resultNum == 3 or resultNum == 4 or resultNum == 9 or resultNum == 10 or resultNum == 11:
        currentCash += wagerAmount
    else:
        currentCash -= wagerAmount
    return int(currentCash)

def passLine(resultNum, currentCash, comeoutRoll, wagerAmount, thePoint):
    if comeoutRoll == True:
        if resultNum == 2 or resultNum == 3 or resultNum == 12:
            currentCash -= wagerAmount
        elif resultNum == 7 or resultNum == 11:
            currentCash += wagerAmount
    else:
        if resultNum == thePoint:
            currentCash += wagerAmount
        elif resultNum == 7:
            currentCash -= wagerAmount
    return int(currentCash)

def dontPassLine(resultNum, currentCash, comeoutRoll, wagerAmount, thePoint):
    if comeoutRoll == True:
        if resultNum == 2 or resultNum == 3:
            currentCash += wagerAmount
        elif resultNum == 7 or resultNum == 11:
            currentCash -= wagerAmount
    else:
        if resultNum == thePoint:
            currentCash -= wagerAmount
        elif resultNum == 7:
            currentCash += wagerAmount
    return int(currentCash)
