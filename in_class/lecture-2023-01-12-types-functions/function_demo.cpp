#include <string>
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

void print5x(string message) {
    cout << message << message << message << message << message << endl;
}

int main(int argc, char* argv[]) {
    cout << add(7, 8) << endl;
    print5x("woot! ");
}



