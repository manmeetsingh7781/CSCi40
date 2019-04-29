// Manmeet Singh
// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function Prototypes
void getChar(int, int);
void base_converter(string, int, int);
unsigned long long int binary_to_decimal(string binary);


int main()
{

	char response;
	int value, from, to;
	string binary_value;
	bool Done = false;
	cout << cout.width(20) << "\bWelcome to Binary n Base Conveter\n" << endl;
	while (not Done) {
		cout << "A. Change Binary to Decimal.\n";
		cout << "B. Change Decimal to another Base.\n>";
		cin >> response;
		response = toupper(response);
		if (response == 'A') {
			cout << "Enter The Number\n>";
			cin >> binary_value;
			cout << binary_to_decimal(binary_value) << endl;
		}
		else if (response == 'B') {
			cout << "Please Enter Number, From Base, and To Base.\n>";
			//cin >> value >> from >> to;
			base_converter("0123456789101112131415", from, to);
			cout << endl;
		}
		cout << "Convert Again? Y/N\n>";
		cin >> response;
		response = toupper(response);
		if (response == 'Y') {
			continue;
		}
		else Done = true;
	}
	cout << endl;
	return 0;
}

// This function returns the Alphabetic characters based on Base number
void getChar(int digit, int base) {
	char letter;
	if (digit > 9 and digit < 36) {
		letter = digit + 55;
		cout << letter;
		return;
	}
	cout << digit;
	return;
}
// Takes a Binary and convert it into the decimal
unsigned long long int binary_to_decimal(string binary) {
	string digits = binary;
	int start = digits.length() - 1, each_number = 0, temper = 0, power = 0;
	unsigned long long int sum = 0;
	while (start >= 0) {
		each_number = static_cast<int>(digits[start] - '0');
		temper = static_cast<int>(each_number * pow(2, power++));
		sum += temper;
		start--;
	}
	return sum;
}

/*
From base feature has to be written
Binary have 2 digits: 0 and 1
Octa have 8 digits: 0 1 2 3 4 5 6 7 8
This means max digit can be Base - 1
*/
// This function takes a number and from which base you want to convert the number into new base
void base_converter(string number, int from_base, int to_base) {

	int *digits = NULL;
	const int SIZE = number.length();
	digits = new int[SIZE];
	int i = 0;
	while (i != SIZE) {
		digits[i] = number[i] - '0';
		cout << digits[i];
		i++;
	}

	/*
	if (from_base > 1 and from_base < 37 and to_base > 1 and to_base < 37) {
		int to_placer = 0, looper = 13, power = 0, answer = 0;
		int to_results[10];
		if (from_base != 10) {
			from_base = 10;
		}
		while (number != 0) {
			answer += static_cast<int>(number % 10 * pow(from_base, power++));
			number /= 10;
		}
		while (answer != 0) {
			to_results[to_placer++] = answer % to_base;
			answer /= to_base;
		}
		for (power = to_placer - 1; power >= 0; power--) {
			if (to_base > 12)
				getChar(to_results[power], to_base);
			else cout << to_results[power];
		}
	}
	else { cout << "Base Limit has been exceeded, please try between 2 and 36\n" << endl;  exit(-1); }
	*/
}
