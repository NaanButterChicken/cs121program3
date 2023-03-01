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
            int info;
            node * next;
    };
    node * head;

    public:
    linkedList() { head = NULL; }//constructor
    //~linkedList(); //destructor
    void addNode(int);
    void print();
    int returnTopNode();

};

/*linkedList::~linkedList() { //since i don't know what's going on here I'll skip it for now
    node * p = head, n; //this line is from the stacks lecture and i really dont know what the head, n is doing
    while (p != NULL) {
        n = p;
        p = p->next;
        delete n;
    }
}*/

void linkedList::addNode(int i) {
    node * n;
    n = new node;
    n->info = i;
    if (head == NULL) {
        head = n;
        n->next = NULL;
    } else {
        node * temp = head;
        n->next = temp;
        head = n;
    }
}

void linkedList::print() {
    node * n = head;
    while (n != NULL) {
        cout << n->info << endl;
        n = n->next;
    }
}

int linkedList::returnTopNode() {
    node * n = head;
    return n->info;
}
