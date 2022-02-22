#include <iostream>
#include <sstream>

using namespace std;

template<class T>
class SLList {
private:
    struct Node {
        T value;
        Node *next;

        Node(T value) : value(value), next(nullptr) {}
    };

    Node *head;
    int _size;

public:
    SLList() : head(nullptr), _size(0) {}
    ~SLList() {
        while (!is_empty()) {
            pop_front();
        }
    }

    int size() const {
        return _size;
    }

    bool is_empty() const {
        return _size == 0;
    }

    T front() const {
        if (is_empty()) {
            // 😱
            throw invalid_argument("The list is empty!");
        } else {
            return head->value;
        }
    }

    void push_back(T item) {
        Node *new_node = new Node(item);
        if (is_empty()) {
            head = new_node;

        } else {
            // head -> something -> new_node
            Node *node;
            for (node = head; node->next != nullptr; node = node->next) {}
            node->next = new_node;
        }
        _size++;
    }

    void pop_front() {
        if (is_empty()) {
            // :)

        } else {
            Node* old_head = head;
            head = head->next;
            delete old_head;
            _size--;
        }
    }

    string to_string() const {
        stringstream ss;
        for (Node *node = head; node != nullptr; node = node->next) {
            ss << node->value;
            if (node->next != nullptr) {
                ss << " ";
            }
        }
        return ss.str();
    }
};

template<class T>
void test(string message, T const &expected, T const &observed) {
    cout << message << endl;
    cout << "Expected: >" << expected << "< Observed: >" << observed << "<" << endl;
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
    test("to_string", (string)"", list.to_string());
    try {
        list.front();
    } catch (std::exception const& ex) {
        cerr << "an exception happened: " << ex.what() << endl;
    }

    list.push_back(1);
    test("empty", false, list.is_empty());
    test("size", 1, list.size());
    test("front", 1, list.front());

    list.push_back(2);
    test("front", 1, list.front());

    list.push_back(7);
    test("empty", false, list.is_empty());
    test("size", 3, list.size());
    test("front", 1, list.front());

    test("to_string", (string) "1 2 7", list.to_string());

    list.pop_front();
    test("size", 2, list.size());
    test("front", 2, list.front());
    test("to_string", (string)"2 7", list.to_string());


    return 0;
}
