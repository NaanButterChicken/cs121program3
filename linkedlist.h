/*
the linked list class defined here is what the stack is going to be built off of.
currently very basic. contains addNode, print, and returnTopNode
will need to add destructors but i'm doing this late and night, don't fully understand what i'm looking at and jsut want to get some basics done
*/

#include <iostream>
using namespace std;

class linkedList {
    private:
    struct node {
        char token;
        node * next;
    };
    node * head;

    public:
    linkedList() { head = NULL; }//constructor
    void addTokenTop(char);
    void addTokenEnd(char);
    void print();
    char returnTopNode();
    char deleteNodeFront();
    char deleteNodeBack();
    bool listEmpty();

    //make a delete all function

};
