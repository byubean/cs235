#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

template<class T>
class SLList {
private:
    struct Node {
        T value;
        Node* next;
        Node(T const& value, Node* next)
            : value(value), next(next) {}
    };

    Node* head;
    int _size;

    Node* find_tail() {
        Node* node = head;
        while (node != nullptr && node->next != nullptr) {
            node=node->next;
        }
        return node;
    }

public:
    SLList(): head(nullptr), _size(0) { }

    int size() const {
        return _size;
    }

    bool is_empty() const {
        return _size == 0;
    }

    T& front() {
        // Yes, this may explode if the list is empty
        return head->value;
    }

    void push_back(T item) {
        Node* new_node = new Node(item, nullptr);

        Node* tail = find_tail();
        if (tail == nullptr) {
            head = new_node;
        } else {
            tail->next = new_node;
        }
        _size++;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        } else {
            Node* next = head->next;
            delete head;
            head = next;
            _size--;
        }
    }

    string to_string() const {
        stringstream out;
        Node* node = head;
        while (node != nullptr) {
            out << node->value;
            if (node->next != nullptr) {
                out << " ";
            }
            node = node->next;
        }
        return out.str();
    }

    bool contains(T const& value) const {
        Node* node = head;
        while (node != nullptr) {
            if (node->value == value) {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    T get(int index) const {
        int pos = 0;
        Node* node = head;
        while (node != nullptr && pos != index) {
            node = node->next;
            pos++;
        }
        // Yes, this will cause trouble if size < index
        return node->value;
    }

    void set(int const index, T const& value) {
        int pos = 0;
        Node* node = head;
        while (node != nullptr && pos != index) {
            node = node->next;
            pos++;
        }
        node->value = value;
    }
};


template<class T>
void test(string const& message, T const& value, T const& expected) {
    cout << message << endl;
    cout << "Expecting: " << expected << endl;
    cout << "Observed: " << value;
    assert (value == expected);
    cout << "✅" << endl << endl;
}


int main() {
    cout << "Testing my linked lists" << endl;
    SLList<string> my_list;

    cout << "Test is_empty and size on brand-new list" << endl;
    test("size()", my_list.size(), 0);
    test("is_empty()", my_list.is_empty(), true);

    cout << "Testing push_back and to_string" << endl;
    my_list.push_back("foo");
    my_list.push_back("bar");
    test("to_string()", my_list.to_string(), (string)"foo bar");

    cout << "Testing is_empty and size on populated list" << endl;
    test("size()", my_list.size(), 2);
    test("is_empty()", my_list.is_empty(), false);

    cout << "Testing contains()" << endl;
    test("contains(\"bar\")", my_list.contains("bar"), true);
    test("contains(\"quux\")", my_list.contains("quux"), false);

    cout << "Testing get()" << endl;
    test("get(0)", my_list.get(0), (string)"foo");
    test("get(1)", my_list.get(1), (string)"bar");

    cout << "Testing set()" << endl;
    cout << "set(1, \"baz\")" << endl;
    my_list.set(1, "baz");
    test("get(1)", my_list.get(1), (string)"baz");

    cout << "Testing front and pop_front" << endl;
    test("front()", my_list.front(), (string)"foo");

    cout << "pop_front()" << endl;
    my_list.pop_front();
    test("size()", my_list.size(), 1);
    test("is_empty()", my_list.is_empty(), false);
    test("front()", my_list.front(), (string)"baz");

    cout << "pop_front()" << endl;
    my_list.pop_front();
    test("size()", my_list.size(), 0);
    test("is_empty()", my_list.is_empty(), true);

    return 0;
}
