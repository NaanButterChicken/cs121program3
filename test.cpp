#include <iostream>
#include "stack.h"
using namespace std;

bool tempIsANumber(char);

int main() {

    //time to see if i can interpret this algorithm and what its saying
    // beginning wiht the expression (3 + 4) * 2
    stack infix; //input
    stack postfix; //final output
    stack temp; //the guy i manipulate

    infix.push(')'); //tippy toppy guy stays
    //infix expression
    infix.push('(');
    infix.push('3');
    infix.push('+');
    infix.push('4');
    infix.push(')');
    infix.push('*');
    infix.push('2');
    /*infix.push('2');
    infix.push('+');
    infix.push('(');
    infix.push('(');
    infix.push('5');
    infix.push(')');
    infix.push('*');
    infix.push('3');
    infix.push(')');*/

    cout << endl; // 2 * ) 4 + 3 ( //is what it prints out

    temp.push('(');
    
    //testing
    cout << "it begins" << endl << "infix: ";
    infix.print();
    cout << endl << "temp: ";
    temp.print();
    cout << endl << "postfix: ";
    postfix.print();
    cout << endl << endl;

    while (!infix.isEmpty()) {
        char infixToken = infix.readTop();
        if(infixToken == '(') {
            cout << "current token is (" << endl;
            temp.push(infix.pop());
        } else if (tempIsANumber(infixToken)) {
            cout << "current token is a number" << endl;
            temp.push(infix.pop());
        } else if (infixToken == ')') {
            cout << "current token is )" << endl;
            infix.pop();
            char c = temp.pop();
            cout << "c: " << c << endl;
            while(c != '(') { 
                postfix.push(c);
                c = temp.pop(); 
                cout << "c now: " << c << endl;

            }
        } else { 
            cout << "current token is operand" << endl;
            temp.push(infix.pop()); //so plus and minus just get stuck in temp. where do i move them to postifix?
            while(temp.readTop() == '/' || temp.readTop() == '*') {
                cout << "while loop activated" << endl; //testing
                char c2 = temp.pop();
                postfix.push(c2);
            }
            
        }

        //testing
        cout << "stacks at end of loop iteration" << endl << "infix: ";
        infix.print();
        cout << endl << "temp: ";
        temp.print();
        cout << endl << "postfix: ";
        postfix.print();
        cout << endl << endl;
    }
    
    //the bethesda fix
    /*while (!temp.isEmpty()) {
        char c3 = temp.pop();
        if (tempIsANumber(c3)) {
            postfix.push(c3);
        }  
    }*/

    cout << "final stack results" << endl << "infix: ";
    infix.print();
    cout << endl << "temp: ";
    temp.print();
    cout << endl << "postfix: ";
    postfix.print();
    cout << endl << endl;
    
    cout << "final product should look like 3 4 + 2 *" << endl;
    //cout << "final product should look like 5 3 * 2 +" << endl;
}

bool tempIsANumber(char c) { //we love copy paste
    if (c == '0') {
        return true;
    } else if (c == '1') {
        return true;
    } else if (c == '2') {
        return true;
    } else if (c == '3') {
        return true;
    } else if (c == '4') {
        return true;
    } else if (c == '5') {
        return true;
    } else if (c == '6') {
        return true;
    } else if (c == '7') {
        return true;
    } else if (c == '8') {
        return true;
    } else if (c == '9') {
        return true;
    } else {
        return false;
    }
}