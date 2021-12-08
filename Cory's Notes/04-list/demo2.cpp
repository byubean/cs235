

#include <string>
#include <vector>

#include "print.h"

using namespace std;


vector<string> reverse(vector<string> items) {
    
    return items;
    
}


int main() {
    
    vector<string> names;
    
    names.push_back("Mary");
    names.push_back("Jane");
    names.push_back("Mark");
    names.push_back("Mark");
    names.push_back("John");
    
    print(names);
    
    print(reverse(names));
    
    return 0;
}


