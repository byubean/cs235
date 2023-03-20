#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template<class T, class P>
class PQ {
    /*
- `add(item, priority)`
- `set_priority(item, priority)`
- `top`
- `pop`
- `is_empty`
     */

    /*
     * - Strategy 3: maintain a lookup for the values
        - BST for values: $O(\log n)$
        - Hashtable for values: $O(1)$
        - Update the table as the heap changes
     - Once value is found, update the priority and percolate
     */
private:
    struct Tuple {
        T item;
        P priority;
    };

    unordered_map<T, int> lookup;
    vector<Tuple> heap;

    void percolate_up(int position) {
        // Implement percolate
        // Keep lookup up-to-date
    }

public:
    bool add(T item, P priority) {
        // Return True if we added it
        // Return false if already in PQ
        Tuple tup(item, priority);

        heap.push_back(tup);
        lookup[item] = heap.size() - 1;

        percolate_up(heap.size() - 1);
    }

    bool set_priority(T item, P priority) {
        // Return false if item not in PQ already
        // or if the priority is the same as the existing
        // Return true otherwise

        // Lookup index using lookup table - go to that tuple
        // Modify the priority
        // Percolate...somewhere
        // Compare existing priority to new priority and go in the right direction

    }

    T const& top() const {
        return heap[0];
    }

    bool pop() {
        // Return true if something popped
        // Else false

        // Swap last item to first position
        // Set lookup information
        // Percolate down
    }

    bool is_empty() const {
        return heap.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
