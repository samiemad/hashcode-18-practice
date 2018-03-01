#!/bin/bash

echo "Compiling..."
mkdir -p bin output
g++ score.cpp --std=c++14 -O3 -o bin/score || exit -1
g++ sol-greedy.cpp --std=c++14 -O3 -o bin/sol || exit -1

if [[ $1 == "all" ]]; then
	files="a_example b_should_be_easy c_no_hurry d_metropolis e_high_bonus";
elif [[ $1 == "fast" ]]; then
	files="a_example b_should_be_easy c_no_hurry";
else
	files="a_example";
fi

for name in $files; do
	printf "Running for file $name...";
	time ./bin/sol < "input/${name}.in" > "output/${name}.out" ;
	score=`./bin/score "output/$name.out" < "input/$name.in"` || exit -1
	echo "Your score for $name is: $score"
	total=$(python -c "print $total+$score")
done

echo "Total score: $total"
