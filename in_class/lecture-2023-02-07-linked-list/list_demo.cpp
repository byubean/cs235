//
// Created by Gordon Bean on 2/7/23.
//

#include "LinkedList.h"
#include <iostream>
using std::cout; using std::endl;

int main() {
    LinkedList<int> numbers;
    cout << numbers.size() << endl;
    cout << std::boolalpha << numbers.is_empty() << endl;
    numbers.push_back(1);
    numbers.push_back(2);
    cout << numbers.size() << endl;
    cout << std::boolalpha << numbers.is_empty() << endl;
    cout << numbers.to_string() << endl;
}