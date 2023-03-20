#include <iostream>
using std::cout;
using std::endl;

int sumto(int x) {
    return x + sumto(x-1);
}

int main(int argc, char* argv[]) {
    cout << sumto(atoi(argv[0])) << endl;
}
