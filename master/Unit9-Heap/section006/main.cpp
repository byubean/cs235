#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template<class T, class P>
class PQ {

    struct Tuple {
        T item;
        P priority;
    };

    unordered_map<T, int> item_location;
    vector<Tuple> heap;

    int parent(int index) {

    }

    int left(int index) {

    }

    int right(int index) {
        return left(index) + 1;
    }

    bool add(T item, P priority) {
        // Return true if the item is now in the PQ
        // Return false if item was already present in PQ
    }

    bool set_priority(T item, P priority) {
        // Return true if it did it right
        // If the item doesn't exist, return false
        // If it didn't change anything, return false
        // Return true otherwise

    }

    T const& top() const {

    }

    bool pop() {
        // Return true if the top item was removed
        // return false if it was empty
    }

    bool is_empty() const {

    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
