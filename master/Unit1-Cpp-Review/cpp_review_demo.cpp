#include <iostream>
#include <string>
int main(int argc, char* argv[]) {
    std::string name;
    if (argc > 1) {
        name = argv[1];
    } else {
        name = "world";
    }
    std::cout << "Hello " << name << "!" << std::endl;
}