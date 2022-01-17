//
// Created by Gordon Bean on 1/12/22.
//

#ifndef LAB1_TODOLIST_H
#define LAB1_TODOLIST_H


#include <iostream>
#include <string>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
private:
    // Private fields go here

public:
    TodoList() {
        cout << "Constructor" << endl;
    }
    ~TodoList() {
        cout << "Destructor" << endl;
    }

    /*
    *   Adds an item to the todo list with the data specified
    *   by the string "_duedate" and the task specified by "_task"
    */
    void add(string _duedate, string _task) {
        cout << "add " << _duedate << " " << _task << endl;
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    int remove(string _task) {
        cout << "remove " << _task << endl;
        return 0;
    }

    /*
    *   Prints out the full todo list to the console
    */
    void printTodoList() {
        cout << "printTodoList" << endl;
    }

    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    void printDaysTasks(string _date) {
        cout << "printDaysTask " << _date << endl;
    }
};

#endif //LAB1_TODOLIST_H
