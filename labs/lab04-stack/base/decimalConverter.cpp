/* decimalConverter.cpp converts an int value to 
 *   its representation in a different base.
 *
 * Joel Adams, July 2001.
 *
 * Input: number, a positive decimal integer
 *         base, the base to which it is to be converted.
 * Output: the base representation of number.
 */

#include <string>

#include <iostream>
#include <stack>

using namespace std;

string convertDecimal(int number, int base);

int main()
{
   cout << "To convert a decimal integer to a different base,\n"
        << " enter a positive integer: ";
   int number;
   cin >> number;
   cout << " then enter the base to which it is to be converted: ";
   int base;
   cin >> base;
 
   cout << '\n' <<  convertDecimal(number, base) << " is the base-" << base
        << " representation of " << number << endl;

   return 0;
}

char baseDigit(int value);

/* convertDecimal() converts a decimal value to its base representation
 * receive: number, an int; and
 *          base, an int.
 * PRE: number is positive &&
 *       2 <= base && base <= 35
 * Return: a string giving the base-base representation of number.
 */
string convertDecimal(int number, int base)
{
   stack<int> intStack;
   int remainder;
   do
   {
      remainder = number % base;
      intStack.push(remainder);
      number /= base;
    }
    while (number != 0);

   string resultString = "";
   char digitChar;
   while ( !intStack.empty() )
   {
      remainder = intStack.top();
      intStack.pop();
      digitChar = baseDigit(remainder);
      resultString += digitChar;
   }
   
   return resultString;
}

/* Table look-up routine for mapping 0-35 to 0-z.
 * Receive: value, an int.
 * PRE: 0 <= value && value <= 35.
 * Return: the 0-z representation of value.
 */
char baseDigit(int value)
{
   const int VALUES_SUPPORTED = 36;
   const char resultArray[VALUES_SUPPORTED] =
     { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
       'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
       'u', 'v', 'w', 'x', 'y', 'z'};

   char result = '*';
   if (0 <= value && value < VALUES_SUPPORTED)
      result = resultArray[value];
   else
      cerr << "\n** baseDigit(value): "
           << value << " outside of range 0.."
           << VALUES_SUPPORTED-1 << endl;

   return result;
}

