#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


template<class T>
class SLList {
private:
    struct Node {
        Node* next;
        T value;
        Node(T value) : value(value), next(nullptr) { }
    };

    Node* head;
    int _size;

public:
    SLList() : head(nullptr), _size(0) { }
    ~SLList() {
        while (!is_empty()) {
            pop_front(); // :)
        }
    }
    int size() const {
        return _size;
    }

    bool is_empty() const {
        return _size == 0;
    }

    T front() const {
        // User should check is_empty before calling
        if (is_empty()) {
            // 😱
            throw invalid_argument("The list is empty. No front to return.");
        } else {
            return head->value;
        }
    }

    void push_back(T item) {
        Node* new_node = new Node(item);

        if (is_empty()) {
            head = new_node;

        } else {
            // find the tail?
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }

            tail->next = new_node;
        }
        _size++;
    }

    void pop_front() {
        if (is_empty()) {
            // 😁
        } else {
            Node* old_head = head;
            head = head->next;
            delete old_head;
            _size--;
        }
    }

    bool contains(T const& item) const {
        if (is_empty()) {
            return false;

        } else {
            // help!
            for (auto node = head; node != nullptr; node = node->next) {
                // something useful 😬
                if (node->value == item) {
                    return true;
                }
            }
            return false;
        }
    }

    string to_string() const {
        stringstream ss;
        for (auto node = head; node != nullptr; node = node->next) {
            ss << node->value;
            if (node->next != nullptr) {
                ss << " ";
            }
        }
        return ss.str();
    }
};

template<class T>
void test(string message, T const& expected, T const& observed) {
    cout << message << endl;
    cout << "Expected was: >" << expected << "< Observed: >" << observed << "<" << endl;
    if (expected == observed) {
        cout << "Passed ✅" << endl;
    } else {
        cerr << "Failed" << endl;
        throw invalid_argument(message);
    }
}

int main() {
    SLList<int> list;
    test("empty", true, list.is_empty());
    test("size", 0, list.size());

    cout << "testing size and is_empty" << endl;
    list.push_back(1);
    test("Not is empty", false, list.is_empty());
    test("size == 1", 1, list.size());

    list.push_back(2);
    test("size == 2", 2, list.size());

    test("list is '1 2'", (string)"1 2", list.to_string());

    list.push_back(42);
    test("list is '1 2 42'", (string)"1 2 42", list.to_string());

    test("front", 1, list.front());
    test("constains", true, list.contains(2));
    test("constains", true, list.contains(1));
    test("constains", true, list.contains(42));
    test("constains", false, list.contains(7));

    list.pop_front();
    test("new front", 2, list.front());
    test("new size", 2, list.size());
}
