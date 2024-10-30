/*
 * File: balancingsymbols.cpp
 * --------------------------
 * Lab 04 P1, DSALGO, Fall 2024, HFU
 * ---------------------------------
 * An example program to show the use of stack
 * to solve the balanced symbols problem
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

/* Main program */
int main() {
    string oneLine;
    stack<char> stackChar;
    bool flag;
    
    while (getline(cin, oneLine)) {
        if (oneLine == "-1") {
            break;
        }
        
        flag = true;
        cout << oneLine << ": ";
        
        for (int i = 0; i < oneLine.size(); ++i) {
            if (oneLine[i] == '[' || oneLine[i] == '(') {
                stackChar.push(oneLine[i]); // keep left symbols in stack
            } else if (oneLine[i] == ']' || oneLine[i] == ')') { // try to match right symbols with corresponding left symbols
                if (stackChar.empty()) {
                    flag = false;
                    break;
                } else if ((stackChar.top() == '[' && oneLine[i] == ']') ||
                    (stackChar.top() == '(' && oneLine[i] == ')')) {
                    stackChar.pop();
                }
            }
        }
        
        if (!stackChar.empty()) {
            flag = false;
        }
        
        if (flag) {
            cout << "balanced" << endl;
        } else {
            cout << "unbalanced" << endl;
            while (!stackChar.empty()) { // clear stack for next line
                stackChar.pop();
            }
        }
    }
    
    return 0;
}