#!/bin/bash

echo "Compiling..."
mkdir -p bin output
g++ score.cpp --std=c++14 -O3 -o bin/score || exit -1
g++ sol-dp.cpp --std=c++14 -O3 -o bin/sol || exit -1

if [[ $1 == "all" ]]; then
	files="example small medium big";
elif [[ $1 == "fast" ]]; then
	files="example small medium";
else
	files="example";
fi

for name in $files; do
	printf "Running for file $name...";
	time ./bin/sol < "input/${name}.in" > "output/${name}.out" ;
	score=`./bin/score "output/$name.out" < "input/$name.in"` || exit -1
	echo "Your score for $name is: $score"
	total=$(python -c "print $total+$score")
done

echo "Total score: $total"
