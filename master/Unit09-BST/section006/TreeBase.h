//
// Created by Gordon Bean on 3/15/22.
//

#ifndef SECTION006_TREEBASE_H
#define SECTION006_TREEBASE_H

#include <string>
#include <iostream>
using namespace std;

template<class T>
struct Node {
    T value;
    int height;
    Node* left;
    Node* right;

    Node(T value) : value(value), height(0), left(nullptr), right(nullptr) {}
};

template<class T>
class TreeBase {
public:
    TreeBase() : root(nullptr) {}
    ~TreeBase() = default;

protected:
    Node<T>* root;

    virtual void clear() = 0;
    virtual bool is_empty() const = 0;
    virtual bool add(T item) = 0;
    virtual bool remove(T item) = 0;
};


/*
 * Handy method for writing tests
 */
template<class T>
void test(string const& message, T const &observed, T const &expected) {
    cout << message << endl;
    cout << "Expected:" << endl << expected << endl << "Observed:" << endl << observed << endl;
    if (expected == observed) {
        cout << "Passed ✅" << endl;
    } else {
        cerr << "Failed" << endl;
        throw invalid_argument(((string) "FAILED TEST: ") + message);
    }
}


#endif //SECTION006_TREEBASE_H
