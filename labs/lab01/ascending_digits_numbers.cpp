// ascending_digits_numbers.cpp

#include <iostream>
#include <vector>

using namespace std;

// To check if the digits of a number are in strictly ascending order. It compares each digit with the previous one from right to left.
bool isAscending(int n) {
	int previousDigit = 10; // Initialize to a digit higher than any possible in the number
	// Check digits form right to left
	while (n > 0) {
		int currentDigit = n % 10;	
		if (currentDigit >= previousDigit) {
			return false; // If the current digit is not less than the previous one, return false
		}
		previousDigit = currentDigit;
		n /= 10; // Move to the next digit
	}
	return true;
}

// To iterate over all numbers between 10 and 9999 to collects those that pass the `isAscending` check.
void findAscendingNumbers(int upperLimit) {
	vector<int> ascendingNumbers;
	for (int i = 10; i < upperLimit; i++) {
		if (isAscending(i)) {
			ascendingNumbers.push_back(i);
		}
	}
	// Print
	for (int n : ascendingNumbers) {
		cout << n << " ";
	}
	cout << endl;
}

int main()
{
	findAscendingNumbers(10000);
	return 0;
}