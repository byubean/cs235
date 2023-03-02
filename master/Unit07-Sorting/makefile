PERF_FILE=many-words.txt
#PERF_FILE=wordle-answers-shuffled.txt

verbose:
	g++ -o sort -DVERBOSE -std=c++14 sort.cpp

fast:
	g++ -o sort -std=c++14 sort.cpp

perf: fast
	echo "No Sort"
	bash -c "time cat $(PERF_FILE) | ./sort nothing > /dev/null"
	echo

	echo "Selection"
	bash -c "time cat $(PERF_FILE) | ./sort selection > /dev/null"
	echo

	echo "Insertion"
	bash -c "time cat $(PERF_FILE) | ./sort insertion > /dev/null"
	echo

	echo "Merge"
	bash -c "time cat $(PERF_FILE) | ./sort merge > /dev/null"
	echo

	echo "Quick"
	bash -c "time cat $(PERF_FILE) | ./sort quick > /dev/null"
	echo


