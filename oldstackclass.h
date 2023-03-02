/*
creates the stack class and all programs relating to it
*/

#include<iostream>
#include"linkedlist.h"
using namespace std;


class stack {
    private:
    struct node {
        char token;
        node * next;
    };
    node * top;

    public:
    stack() {top = NULL;} //constructor
    void push(char);
    char pop();
    void print();
    char readTop();
    bool isEmpty();

};

void stack::push(char c) {
    node * n = new node;
    n->token = c;
    n->next = top;
    top = n;
}

char stack::pop() {
    char c = '0'; //initialize it to something as default
    node * current;
    if (top == NULL) {
        cout << "stack empty" << endl;
    } else {
        c = top->token;
        current = top;
        top = top->next;
        current->next = NULL;
        delete current;
    }
    return c;
}

void stack::print() {
    node * n = top;
    while (n != NULL) {
        cout << n->token << " ";
        n = n->next;
    }
}


char stack::readTop() {
    return top->token;
}

bool stack::isEmpty() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}
