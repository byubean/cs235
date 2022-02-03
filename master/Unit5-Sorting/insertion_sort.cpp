#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
void insertion_sort(vector<T>& stuff) {
    for (int i = 0; i < stuff.size(); i++) { // Move the partition from 0 to n-2
        cout << endl << "i is " << i << endl;

        // Grab item i and save it
        T item = stuff[i];

        // Shift the sort stuff to the left until I find where item belongs
        int j = i;
        while (j > 0 && item < stuff[j-1]) {
            stuff[j] = stuff[j-1];
            j--;
        }

        // Insert the item in it's sorted position
        stuff[j] = item;

        for (auto thing : stuff) {
            cout << thing << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    vector<string> stuff;
    for (int i = 1; i < argc; i++) {
        stuff.push_back(argv[i]);
    }
    insertion_sort(stuff);
    cout << endl;
    for (auto word : stuff) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}