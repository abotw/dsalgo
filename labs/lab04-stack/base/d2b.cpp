/*
 * File: d2b.cpp
 * ------------------------
 * This program uses a stack to convert the base-ten representation 
 * of a positive integer entered as input to base two, which is
 * then output.
 * ------------
 * Last updated: Wed Oct 30 22:38:57 CST 2024
 * Source: http://cms.dt.uh.edu/Faculty/LinH/courses/cs3304/Slides/42444-Nyhoff_5-8ppts/Chapter07/CodeSamplesChapter07.htm
 */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    unsigned n,                 // the number to be converted
             rem;               // remainder when n is divided by 2
    stack<unsigned> stackRem;   // stack of remainders
    char resp;                   // user response
    
    do {
        cout << "Enter positive integer to convert: ";
        cin >> n;
        
        while (n != 0) {
            rem = n % 2;
            stackRem.push(rem);
            n /= 2;
        }
        cout << "Base-two representation: ";
        
        while (!stackRem.empty()) {
            rem = stackRem.top();
            stackRem.pop();
            cout << rem;
        }
        cout << '\n' << "\nMore (Y or N)? ";
        cin >> resp;
    } while (resp == 'Y' || resp == 'y');
    
    return 0;
}