#include<iostream>
#include"stack.h"
using namespace std;


void stack::push(char c) {
    listItem.addTokenTop(c);
}

char stack::pop() {
    char storedToken = listItem.deleteNodeFront();
    return storedToken;
}

void stack::print() {
    listItem.print();

}

char stack::readTop() {
    char top = listItem.returnTopNode();
    return top;
}

bool stack::isEmpty() {
    bool listIsEmpty = listItem.listEmpty();
    return listIsEmpty;
}