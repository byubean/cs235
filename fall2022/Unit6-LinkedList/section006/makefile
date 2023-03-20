all:
	g++ -o test_list -g main.cpp

test: all
	valgrind --leak-check=full -s ./test_list
