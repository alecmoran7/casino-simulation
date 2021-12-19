echo "What strategy type to run?"
echo "Options are field, dontpass, pass"
read strategyType
if ![$strategyType == "field" || $strategyType == "dontpass" || $strategyType == "pass"]; then
  echo "Not one of the specified types, exiting..."
  exit 2
fi
echo "How many iterations to run?"
read itNum
echo "Running $itNum iterations"
for ((i=0; i<$itNum; i++))
do
  python3 ../programs/crapsMulti.py field | grep House >> cData.txt
done
