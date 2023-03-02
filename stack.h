/*
creates the stack class and all programs relating to it
*/

#include<iostream>
#include"linkedlist.h"
using namespace std;


class stack {
    private:
    linkedList * listPtr;
    linkedList listItem;

    public:
    stack() {
        linkedList * stackPtr;
        stackPtr = new linkedList();
    }
    void push(char);
    char pop();
    void print();
    char readTop();
    bool isEmpty();

};


