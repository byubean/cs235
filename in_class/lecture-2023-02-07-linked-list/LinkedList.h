#ifndef IN_CLASS_LINKEDLIST_H
#define IN_CLASS_LINKEDLIST_H

#include <cstdlib>
#include <string>
#include <sstream>
using std::string;


template <class T>
class LinkedList {
private:
    class Node {
    public:
        Node(T thing) : thing(thing), next(nullptr) { }
        T thing;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t _size;

public:
    LinkedList() : head(nullptr), tail(nullptr), _size(0) {}
    ~LinkedList() {
        // TODO
    }

    size_t size() const {
        return _size;
    }

    bool is_empty() const {
        return _size == 0;
    }

    void push_back(T thing) {
        if (is_empty()) {
            head = new Node(thing);
            tail = head;
        } else {
            tail->next = new Node(thing);
            tail = tail->next;
        }
        _size++;
    }

    string to_string() const {
        std::stringstream ss;
        for (Node* node = head; node != nullptr; node = node->next) {
            ss << node->thing << ' ';
        }
        return ss.str();
    }



};

#endif //IN_CLASS_LINKEDLIST_H
