//
// Created by Gordon Bean on 2/23/22.
//
#include <string>
#include <iostream>
using namespace std;

void foo() {
    throw 7;
}

void bar() {
    string error = "just fine";
    throw error;
}

int main() {
    try {
        //foo();
        bar();
    } catch (int error) {
        cerr << "I just caught an int: " << error << endl;
    } catch (string error) {
        cerr << "I just caught a string: " << error << endl;
        if (error == "just fine") {
            cerr << "nevermind" << endl;
        }
    }
    foo();
}



