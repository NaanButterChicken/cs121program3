#include <iostream>
//#include "linkedlist.h"
#include "stack.h"
using namespace std;

int main() {
    linkedList infix;
    stack tester;

    infix.addTokenTop('a');
    infix.addTokenTop('b');
    infix.addTokenTop('c');
    infix.addTokenEnd('d');
    infix.print();
    cout << endl << "top node: " << infix.returnTopNode() << endl;
    infix.deleteNodeBack();
    infix.deleteNodeFront();
    infix.print();
    cout << endl;
}

