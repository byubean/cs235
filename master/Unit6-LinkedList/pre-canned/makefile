all:
	g++ -g -o list_test main.cpp

test: all
	valgrind -s --leak-check=full ./list_test

