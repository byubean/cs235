#include "house.h"
#include <iostream>

int main() {
    House h1 = House(700, "123 St", "12345");
    cout << h1.str() << endl;
}