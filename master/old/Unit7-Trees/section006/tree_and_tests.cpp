#include <iostream>

#include "TreeBase.h"
#include <algorithm>
#include <vector>

template<class T>
class Tree : public TreeBase<T> {
public:
    Tree() {}

    ~Tree() {
        clear();
    }

    int height() const {
        return this->root == nullptr ? -1 : this->root->height;
    }

    void clear() override {
        _clear(this->root);
    }

    void _clear(Node<T> *&node) {
        if (node == nullptr) {
            return;
        }
        _clear(node->left);
        _clear(node->right);
        delete node;
    }

    bool is_empty() const override {
        return this->root == nullptr;
    };

    bool add(T item) override {
        return _add(this->root, item);
    };

    bool _add(Node<T> *&node, T item) {
        if (node == nullptr) {
            // This is the place!
            node = new Node<T>(item);
            return true;
        }

        if (node->value == item) {
            return false;

        } else if (item < node->value) {
            bool added = _add(node->left, item);
            if (added) { _update_height(node); }
            return added;

        } else { // item > node->value
            bool added;
            if ((added = _add(node->right, item))) { _update_height(node); }
            return added;
        }
    }

    void _update_height(Node<T> *&node) {
        if (node == nullptr) { return; }

        node->height = 1 + max(
                node->left == nullptr ? -1 : node->left->height,
                node->right == nullptr ? -1 : node->right->height
        );
    }

    bool remove(T item) override {
        return _remove(this->root, item);
    }

    bool _remove(Node<T> *&node, T item) {
        if (node == nullptr) {
            return false;
        }

        bool removed = false;

        if (node->value == item) {
            // have no children
            // have one child
            if (node->left == nullptr) {
                auto tmp = node;
                node = node->right;
                delete tmp;
                removed = true;

            } else if (node->right == nullptr) {
                auto tmp = node;
                node = node->left;
                delete tmp;
                removed = true;

            } else {
                // have two children -> swap IOP value
                // IOP is rightmost child in left branch
                // Replace node value with IOP value
                // Delete IOP value from left tree
                T const &iop_value = _get_iop_value(node);
                node->value = iop_value;
                _remove(node->left, iop_value);
                removed = true;
            }

        } else if (item < node->value) {
            removed = _remove(node->left, item);

        } else {
            removed = _remove(node->right, item);
        }

        if (removed) {
            _update_height(node);
        }

        return removed;
    }

    T const &_get_iop_value(Node<T> *const &node) {
        // Will only ever call this if node->left is not null
        //  so no need to check

        auto tmp = node->left;
        while (tmp->right != nullptr) {
            tmp = tmp->right;
        }
        return tmp->value;
    }

    vector<T> query(T const &item) {
        // Return every value that is "close" to item
        // Define close: +/- 3 from item (inclusive)
        vector<T> items_found;
        _query(this->root, item, items_found);
        return items_found;
    }

    void _query(Node<T> *const &node, T const &item, vector<T> &items_found) {
        if (node == nullptr) { return; }

        _query(node->left, item, items_found);

        // current node
        if (abs(node->value - item) <= 3) {
            items_found.push_back(node->value);
        }

        _query(node->right, item, items_found);
    }
};


int main() {
    Tree<int> tree;
    test("is empty", tree.is_empty(), true);
    test("height", tree.height(), -1);

    test("add 7", tree.add(7), true);
    test("height", tree.height(), 0);
    test("add 7 dup", tree.add(7), false);
    test("height", tree.height(), 0);

    test("add 8", tree.add(8), true);
    test("height", tree.height(), 1);
    test("add 5", tree.add(5), true);
    test("height", tree.height(), 1);
    test("add 3", tree.add(3), true);
    test("height", tree.height(), 2);

    auto items = tree.query(9);
    test("query count",(int) items.size(), 2);

    vector<int> expected = {7, 8};
    for (int i = 0; i < items.size(); i++) {
        test("query item", items[i], expected[i]);
    }

    test("remove 3", tree.remove(3), true);
    test("remove 3 again", tree.remove(3), false);
    test("height", tree.height(), 1);

    test("remove 7", tree.remove(7), true);
    test("height", tree.height(), 1);

    test("remove 5", tree.remove(5), true);
    test("height", tree.height(), 0);

    test("remove 8", tree.remove(8), true);
    test("height", tree.height(), -1);

    return 0;

}
