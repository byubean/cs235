#include <iostream>
#include "TreeBase.h"

#include <algorithm>
#include <vector>

// Not self-balancing
// Updating the min-max interval
// Templates
// Query
// Inheritance

template<class T>
class Tree : public TreeBase<T> {

public:
    Tree() {}

    ~Tree() {
        clear();
    }

    void clear() {
        _clear(this->root);
    }

    void _clear(Node<T> *&node) {
        if (node == nullptr) { return; }
        _clear(node->left);
        _clear(node->right);
        delete node;
    }

    bool is_empty() const override {
        return this->root == nullptr;
    }

    int height() const {
        return this->root == nullptr ? -1 : this->root->height;
    }

    bool add(T item) override {
        return _add(this->root, item);
    }

    bool _add(Node<T> *&node, T item) {
        if (node == nullptr) {
            // This is the place!
            node = new Node<T>(item);
            return true;
        }
        if (node->value == item) {
            return false;

        } else if (node->value < item) {
            bool added = _add(node->left, item);
            if (added) {
                // Update the height
                _update_height(node);
                // Check for balance here
                // Fix balance if necessary
            }
            return added;

        } else { // node->value > item
            bool added = _add(node->right, item);
            if (added) { _update_height(node); }
            return added;
        }
    }

    void _update_height(Node<T> *&node) {
        if (node == nullptr) {
            return;
        }
        node->height = 1 + max(
                node->left == nullptr ? -1 : node->left->height,
                node->right == nullptr ? -1 : node->right->height
        );
    }

    bool remove(T item) override {
        return _remove(this->root, item);
    }

    bool _remove(Node<T> *&node, T item) {
        if (node == nullptr) { return false; }

        if (node->value == item) {
            // Leaf or single child
            if (node->left == nullptr) {
                auto tmp = node;
                node = node->right;
                delete tmp;
                _update_height(node);
                return true;

            } else if (node->right == nullptr) {
                auto tmp = node;
                node = node->left;
                delete tmp;
                _update_height(node);
                return true;

            } else {
                // Two children -> IOP
                T &iopValue = _get_iop_value(node);
                node->value = iopValue;
                _remove(node->left, iopValue);
                _update_height(node);
                return true;
            }
        } else if (node->value < item) {
            bool removed = _remove(node->left, item);
            if (removed) { _update_height(node); }
            return removed;

        } else {
            bool removed = _remove(node->right, item);
            if (removed) { _update_height(node); }
            return removed;
        }
    }

    T &_get_iop_value(Node<T> *const &node) {
        // Will only ever call this when there are two childen on node,
        //  so we won't assert node is non-null
        auto tmp = node->left;
        while (tmp->right != nullptr) {
            tmp = tmp->right;
        }
        return tmp->value;
    }

    vector<T> query(T item) {
        // Return any item within +/- 3 steps inclusive from item
        vector<T> items_found;
        _query(this->root, item, items_found);
        return items_found;
    }

    void _query(Node<T>* const& node, T item, vector<T>& items_found) {
        if (node == nullptr) { return; }
        // Go left
        _query(node->left, item, items_found);

        // Check current
        if (abs(item - node->value) <= 3) {
            items_found.push_back(node->value);
        }

        // Go right
        _query(node->right, item, items_found);
    }
};


int main() {
    Tree<int> tree;
    test("is empty", tree.is_empty(), true);
    test("height", tree.height(), -1);
    test("add 7", tree.add(7), true);
    test("add 7 dup", tree.add(7), false);
    test("height", tree.height(), 0);
    test("add 5", tree.add(5), true);
    test("height", tree.height(), 1);
    test("add 8", tree.add(8), true);
    test("height", tree.height(), 1);
    test("add 3", tree.add(3), true);
    test("height", tree.height(), 2);
    test("is empty", tree.is_empty(), false);

    vector<int> expected = {7, 8};
    auto observed = tree.query(10);
    for (int i = 0; i < observed.size(); i++){
        test("query item", observed[i], expected[i]);
    }

    test("remove 1000", tree.remove(1000), false);

    test("remove 3", tree.remove(3), true);
    test("remove 3 again", tree.remove(3), false);
    test("height", tree.height(), 1);
    test("remove 7", tree.remove(7), true);
    test("height", tree.height(), 1);
    test("remove 5", tree.remove(5), true);
    test("height", tree.height(), 0);
    test("remove 8", tree.remove(8), true);
    test("height", tree.height(), -1);
    test("is empty", tree.is_empty(), true);

    return 0;
}
