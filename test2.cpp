/*
main program file
where the input goes and spits out the output
*/
#include<iostream>
//#include"linkedlist.h"
#include"stack.h"
using namespace std;

void fillInfix(linkedList&);
bool isANumber(char);
bool isPrecedenceGreater(char, char);
linkedList infixPostfixAlgorithm(linkedList);

//final steps: user input. change fillInfix probably so its not quite so long. i feel like the professor will consider such long code to be wasteful

int main() {
    bool runConversion = true;
    while (runConversion) {
        linkedList infix; //input

        fillInfix(infix);
        
        cout << infixPostfixAlgorithm(infix) << endl;

        char cont;
        cout << "want to run another? y/n ";
        cin >> cont;
        if (cont == 'n') {
            runConversion = false;
        }
    }
}

void fillInfix(linkedList& infix) { //temporary    
    bool charsToEnter = true;
    while (charsToEnter) {
        char c;
        cout << "enter char: ";
        cin >> c;
        infix.addTokenEnd(c);
        cout << "enter another? y/n";
        cin >> c;
        if (c == 'n') {
            charsToEnter = false;
        }
    }
    infix.print();
    cout << endl;
}

bool isANumber(char c) {
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
        cout << "precedence greater" << endl;
        return true;
    } else if ((tempTop == '*' || tempTop == '/') && (infixToken == '*' || infixToken == '/')) { //precedence equal
        cout << "precedence equal" << endl;
        return true;
    } else if ((tempTop == '+' || tempTop == '-') && (infixToken == '+' || infixToken == '-')) { //precedence equal
        cout << "precedence equal" << endl;
        return true;
    } else if ((tempTop == '+' || tempTop == '-') && (infixToken == '*' || infixToken == '/')) { //precendence lower
        cout << "precedence lower" << endl;
        return false;
    } else {
        cout << "an error probably occrued" << endl;
        return false; //just in case
    }
}

linkedList infixPostfixAlgorithm(linkedlist infix) {
    linkedList postfix;
    stack temp;
    infix.addTokenEnd(')');
    temp.push(')');
    while (!temp.isEmpty()) {
        cout << endl; //testing
        char infixToken = infix.deleteNodeFront(); //hypothetically, if this function works, it should grab the first token on the left
        if (infixToken == '(') {
            cout << "inixToken is (" << endl; //test
            temp.push(infixToken);
        } else if (isANumber(infixToken)) { 
            cout << "infixToken is a number" << endl; //test
            postfix.addTokenEnd(infixToken);
            //temp.push(infixToken);
        } else if (infixToken == ')') {
            cout << "infixToken is )" << endl; //test
            char c = temp.pop();
            cout << "c: " << c << endl; //test
            while (c != '(') {
                postfix.addTokenEnd(c);
                if (temp.isEmpty()) {
                    break;
                }
                c = temp.pop();
                cout << "c is now: " << c << endl; //test
            }
        } else {
            cout << "infixToken is operator" << endl; //test
            while (isPrecedenceGreater(temp.readTop(), infixToken)/* || temp.readTop() == '('*/) {
                cout << "while loop activated" << endl; //testing
                if (temp.isEmpty()) {
                    break;
                }
                char c2 = temp.pop();
                postfix.addTokenEnd(c2);
            }
            temp.push(infixToken);
        }

        //testing
        cout << "end of iteration... \ninfix: ";
        infix.print();
        cout << endl << "temp: ";
        temp.print();
        cout << endl << "postfix: ";
        postfix.print();
        cout << endl;

    }

    return postfix;
}