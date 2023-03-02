#include <iostream>
#include "stack.h"
using namespace std;

bool tempIsANumber(char);
bool isPrecedenceGreater(char, char);

int main() {

    //time to see if i can interpret this algorithm and what its saying
    // beginning wiht the expression (3 + 4) * 2
    stack infix; //input
    stack postfix; //final output
    stack temp; //the guy i manipulate
    //making infix and postfix into linked lists probably
    //still feel like none of this will matter if i cant get the damn algorithm working
    //that doesnt even begin with evaluating the results of the postfix expression

    
    //infix expression
    infix.push(')'); //added last as the closing dude
    /*infix.push('2');
    infix.push('*');
    infix.push(')');
    infix.push('4');
    infix.push('+');
    infix.push('3');
    infix.push('(');*/

    // 2 + ((5) * 3)
    infix.push(')');
    infix.push('3');
    infix.push('*');
    infix.push(')');
    infix.push('5');
    infix.push('(');
    infix.push('(');
    infix.push('+');
    infix.push('2');

    cout << endl;
    
    temp.push('(');
    
    //testing
    cout << "it begins" << endl << "infix: ";
    infix.print();
    cout << endl << "temp: ";
    temp.print();
    cout << endl << "postfix: ";
    postfix.print();
    cout << endl << endl;

    while (!temp.isEmpty()) {
        char infixToken = infix.pop();
        if(infixToken == '(') {
            cout << "current token is (" << endl;
            temp.push(infixToken);
        } else if (tempIsANumber(infixToken)) {
            cout << "current token is a number" << endl;
            postfix.push(infixToken);

        } else if (infixToken == ')') {
            cout << "current token is )" << endl;
            char c = temp.pop(); 
            cout << "c: " << c << endl;
            while(c != '(') { 
                postfix.push(c);
                if (temp.isEmpty()) {
                    break;
                }
                c = temp.pop(); 
                cout << "c now: " << c << endl;
            }
        } else { 
            cout << "current token is operand" << endl;
            //temp.push(infixToken); //so plus and minus just get stuck in temp. where do i move them to postifix?
            while(isPrecedenceGreater(temp.readTop(), infixToken)) {
                //read current top of stack while infix token is higher precedence than top of stack temp
                //comparing temp.readtop against infixtoken
                cout << "while loop activated" << endl; //testing
                
                if (temp.isEmpty()) {
                    break;
                }
                char c2 = temp.pop();
                postfix.push(c2);
            }
            temp.push(infixToken);
            
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

    cout << "final stack results" << endl << "infix: ";
    infix.print();
    cout << endl << "temp: ";
    temp.print();
    cout << endl << "postfix: ";
    postfix.print();
    cout << endl << endl;
    
    //cout << "final product should look like * 2 + 4 3" << endl;
    cout << "final product should look like 5 3 * 2 +" << endl;
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

bool isPrecedenceGreater(char tempTop, char infixToken) {
    //top of stack higher precendence (*/) than infixtoken returns true
    if ((tempTop == '*' || tempTop == '/') && (infixToken == '+' || infixToken == '-')) { //precedence greater
        return true;
    } else if ((tempTop == '*' || tempTop == '/') && (infixToken == '*' || infixToken == '/')) { //precedence equal
        return true;
    } else if ((tempTop == '+' || tempTop == '-') && (infixToken == '+' || infixToken == '-')) { //precedence equal
        return true;
    } else if ((tempTop == '+' || tempTop == '-') && (infixToken == '*' || infixToken == '/')) { //precendence lower
        return false;
    } else {
        cout << "an error probably occrued" << endl;
        return false; //just in case
    }
}
