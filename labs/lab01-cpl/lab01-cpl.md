Sun Sep 29 08:03:12 CST 2024
# Lab 01: C语言知识相关
## Q1: Ascending Digit Numbers, 数位升序数字

> 命名规范
> 
> 程序取名：`ascending_digits_numbers.cpp`

To find all numbers less than 10,000 where each digit is in ascending order from left to right (i.e., the higher-order digits are less than the lower-order digits).

This program finds all numbers less than 10000 where the digits are in ascending order.
For example, 25, 349, 2468 are valid, but 32, 845 are not.

编程求出 10000 以内的所有符合如下条件的数，其高位数字小于低位数字。如 25，349，2468 等，但 32， 845 不符合条件。

---

$$
n\in[1, 10000]
$$

<img src="https://decimal.info/image/decimal-place-value-names.png" height="300">

| 1             | 0         | 0        | 0    | 0    |
| ------------- | --------- | -------- | ---- | ---- |
| ten thousands | thousands | hundreds | tens | ones |

ten thousands > thousands > hundreds > tens > ones

high-digit number > low-digit number

$$
n\in[12, 6789]
$$

### Code

```cpp
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
		num /= 10; // Move to the next digit
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
	for (int n : ascedningNumbers) {
		cout << num << " ";
	}
	cout << endl;
}

int main()
{
	findAscendingNumbers(10000);
	return 0;
}
```