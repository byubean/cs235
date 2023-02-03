#include <iostream>
#include <sstream>

#include "house.h"
#include "house.h"

using namespace std;

House::House(int sqFootage, string address, string zipCode) 
    : sqFootage(sqFootage), address(address), zipCode(zipCode) 
    {
        // Nothing needed here
    }
    
int House::getSqFootage() const {
    return sqFootage;
}
string House::getAddress() const {
    return address;
}
string House::getZipCode() const {
    return zipCode;
}
string House::str() const {
    stringstream ss;
    ss << address << " " << zipCode << " " << sqFootage << "sqFt";
    return ss.str();
}

int main() {
    House h1 = House(700, "123 St", "12345");
    cout << h1.str() << endl;
}