//
// Created by Gordon Bean on 3/16/23.
//

#ifndef IN_CLASS_BST_H
#define IN_CLASS_BST_H
template <class NT>
struct Node {
    NT value;
    Node* left;
    Node* right;

    Node(NT item) : value(item), left(nullptr), right(nullptr) {}

};

template<class T>
class Set {
private:
    typedef Node<T> N;

    int _size;
    N* _root;

    bool _contains(N*& node, T item) {
        if (node == nullptr) {
            return false;
        }

        if (node->value == item) {
            return true;
        }

        if (node->value > item) {
            return _contains(node->left, item);
        } else {
            return _contains(node->right, item);
        }
    }

    bool _add(N*& node, T item) {
        if (node == nullptr) {
            node = new N(item);
            return true;
        }

        if (node->value == item) {
            return false;
        }

        if (node->value > item) {
            return _add(node->left, item);
        } else {
            return _add(node->right, item);
        }
    }

    bool _remove(N*& node, T item) {
        /* :) */
    }

public:
    bool add(T item) {
        if (_add(_root, item)) {
            _size++;
            return true;
        } else {
            return false;
        }
    }

    bool remove(T item) {
        if (_remove(_root, item)) {
            _size--;
            return true;
        } else {
            return false;
        }
    }

    void clear() {

    }

    bool contains(T item) {
        return _contains(_root, item);
    }

    int size() {
        return _size;
    }
};

#endif //IN_CLASS_BST_H
