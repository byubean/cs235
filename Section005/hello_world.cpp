#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string name;
    if (argc < 2) {
        name = "class!!";
    } else {
        name = argv[1];
    }
    cout << "Hello " << name << endl;
}
