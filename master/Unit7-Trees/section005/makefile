build:
	g++ -g -o tests main.cpp

test: build
	valgrind --leak-check=full ./tests
