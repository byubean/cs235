#pragma once
#include <string>
using namespace std;

class House {
    private:
    int sqFootage;
    string address;
    string zipCode;
    public:
    House(int, string, string);
    int getSqFootage() const;
    string getAddress() const;
    string getZipCode() const;
    string str() const;
};