// Manmeet Singh
// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// function Prototypes
void getChar(int);
int getInt(char);
void base_converter(string, int, int);


int main()
{

	char response;
	int from, to;
	string binary_value, value;
	bool Done = false;
	cout << cout.width(20) << "\bWelcome to Binary n Base Conveter\n" << endl;
	while (not Done) {
		cout << cout.width(20)<< "\bChange One Base to Another Base.\n\n";
		cout << "Please Enter Number, From Base, and To Base.\n>";
		cin >> value >> from >> to;
		base_converter(value, from, to);
		cout << endl;
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
void getChar(int digit) {
	char letter;
	if (digit > 9 and digit < 36) {
		letter = digit + 55;
		cout << letter;
		return;
	}
	cout << digit;
	return;
}

int getInt(char letter) {
	int number;
	if (letter >= 'A' and letter <= 'Z') {
		number = letter - 55;
		return number;
	}
	return letter;
}

/*
From base feature has to be written
Binary have 2 digits: 0 and 1
Octa have 8 digits: 0 1 2 3 4 5 6 7 8
This means max digit can be Base - 1
*/
// This function takes a number and from which base you want to convert the number into new base
void base_converter(string number, int from_base, int to_base) {
	int *to_results = NULL;
	int SIZE = number.length() - 1, i = SIZE, from_power = 0, to_tenth_sum = 0, to_tenth_remainders = 0, to_placer = 0, looper = 13, power = 0, answer = 0;
	to_results = new int[SIZE];
	if (from_base > 1 and from_base < 37 and to_base > 1 and to_base < 37) {
		while (i > -1) {
			if (from_base > 10 and number[i] > 10 and getInt(number[i]) < from_base) {
				cout << getInt(number[i]);
			}
			else if ((number[i] - '0') < from_base) {
				to_tenth_sum += static_cast<int>((number[i] - '0') * pow(from_base, from_power++));

			}
			else {
				cout << "Number '" << number[i] << "' is Higher then Home Base: " << from_base << endl;
				break;
			}
			i--;
		}
		while (to_tenth_sum != 0) {
			to_results[to_placer++] = to_tenth_sum % to_base;
			to_tenth_sum /= to_base;
		}
		for (power = to_placer - 1; power >= 0; power--) {
			if (to_base > 10)
				getChar(to_results[power]);
			else cout << to_results[power];
		}
	}
	else { cout << "Base Limit has been exceeded, please try between 2 and 36\n" << endl;  exit(-1); }
}
