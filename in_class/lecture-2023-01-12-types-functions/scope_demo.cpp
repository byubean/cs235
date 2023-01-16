#include <iostream>
using namespace std;

const int FOO = 7;

void printFoo(int bar) {
    cout << FOO << endl << bar << endl;
}

int main(int argc, char* argv[]) {
    printFoo(8);
}