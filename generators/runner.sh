filename_number=$[($RANDOM)]
filename=$filename_number.txt
#echo $filename

../programs/cpp_version/craps/run 100000 0 100 2 | grep House > ./raw-data/0/$filename
