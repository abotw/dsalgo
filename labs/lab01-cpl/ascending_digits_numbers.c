// Sun Sep 29 16:16:38 CST 2024
// ascending_digits_numbers.c

#include <stdio.h>

// To check if the digits of a number are in strictly ascending order. It compares each digit with the previous one from right to left.
int isAscending(int n) {
	int previousDigit = 10; // Initialize to a digit higher than any possible in the number
	// Check digits form right to left
	while (n > 0) {
		int currentDigit = n % 10;	
		if (currentDigit >= previousDigit) {
			return 0; // If the current digit is not less than the previous one, return false
		}
		previousDigit = currentDigit;
		n /= 10; // Move to the next digit
	}
	return 1;
}

// To iterate over all numbers between 12 and 9999 to collects those that pass the `isAscending` check.
void findAscendingNumbers(int upperLimit) {
	int count = 0;
	for (int i = 10; i < upperLimit; i++) {
		if (isAscending(i)) {
			printf("%d\t", i);
			count++;
			if (count % 10 == 0) {
				puts("");
			}
		}
	}
	printf("\nThe number of ascending digits numbers is: %d\n", count);
}

int main()
{
	findAscendingNumbers(10000);
	return 0;
}