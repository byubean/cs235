#include <iostream>
#include "TodoList.h"

void different() {
    TodoList other;
}

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    TodoList list;
    TodoList* another = new TodoList();
    different();
    delete another;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
