/*
 * File: baseconversion.cpp
 * ------------------------
 * This program uses a stack to convert the base-ten representation 
 * of a positive integer entered as input to base N (N in [2, 9]),
 * which is then output.
 * ---------------------
 * Last updated: Wed Oct 30 22:52:12 CST 2024
 */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    unsigned N,                 // base N
             n,                 // the number to be converted
             rem;               // remainder when n is divided by N
    stack<unsigned> stackRem;   // stack of remainders
    char resp;                  // user response
    
    do {
        cout << "Enter base to convert: ";
        cin >> N;
        cout << "Enter positive integer to convert: ";
        cin >> n;
        
        while (n != 0) {
            rem = n % N;
            stackRem.push(rem);
            n /= N;
        }
        cout << "Base-" << N << " representation: ";
        
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