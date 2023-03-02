#include <iostream>
#include"linkedlist.h"
using namespace std;


void linkedList::addTokenTop(char t) {
    node * n;
    n = new node;
    n->token = t;
    if (head == NULL) {
        head = n;
        n->next = NULL;
    } else {
        node * temp = head;
        n->next = temp;
        head = n;
    }
}

void linkedList::addTokenEnd(char t) {
    node * n = new node;
    n->token = t;
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        node * p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
    }
}

char linkedList::deleteNodeFront() {
    node * n = head;
    char storedData = n->token;
    if (n == NULL) {
        cout << "list empty" << endl;
    } else {
        head = n->next;
        n->next = NULL;
        delete n;
    }

    return storedData;
}

char linkedList::deleteNodeBack() {
    node * curr;
    node * prev;
    char c = NULL;
    if (head == NULL) {
        cout << "list empty" << endl;
    } else {
        curr = head;
        prev = head;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        c = curr->token;
        delete curr;
    }
    return c;
}

void linkedList::print() {
    node * n = head;
    while (n != NULL) {
        cout << n->token;
        n = n->next;
    }
}

char linkedList::returnTopNode() {
    node * n = head;
    return n->token;
}

bool linkedList::listEmpty() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}