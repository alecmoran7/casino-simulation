import os
import subprocess
import sys

totalNumLines = 0
percentageSum = 0.000
allPercentages = []
sumOfPercentages = 0

# print("Arg1 is " + str(sys.argv[1]))
fileName = sys.argv[1]
inputFile = open(fileName, "r")
for line in inputFile:
    # print(line)
    lineValue = line.split(':')[1].replace("%\n","").strip()
    nextPercent = float(lineValue)
    allPercentages.append(nextPercent)
    sumOfPercentages += nextPercent

print(allPercentages)
listLength = len(allPercentages)
avgPercent = sumOfPercentages / listLength
print("Num percentages: " + str(listLength))
print("Average: " + str(avgPercent))
    