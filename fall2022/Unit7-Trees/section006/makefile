build:
	g++ -g -o tests tree_and_tests.cpp

test: build
	valgrind --leak-check=full ./tests

