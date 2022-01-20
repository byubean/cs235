#include <iostream>
#include <sstream>

#include "house.h"
#include "house.h"

using namespace std;

House::House(int sqFootage, string address, string zipCode)
        : address(address), zipCode(zipCode), sqFootage(sqFootage)
{
    // Nothing else needed here
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
