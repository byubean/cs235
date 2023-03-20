#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // argv[1] is the bullet
    string bullet = (argc > 1) ? argv[1] : "🔹💪🏻";
    string line;
    while (getline(cin,line)) {
        cout << bullet << " " << line << endl;
    }
    return 0;
}
