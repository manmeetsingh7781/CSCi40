// Manmeet Singh
// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// function Prototypes
void start_conveter();
void getChar(int);
int getInt(char);
void base_converter(string, int, int);
void create_table(int, int);


int main() {
	// This is the main thread for binary conveter
	start_conveter();
	cin.get();
	cout << endl;
	return 0;
}


// This function is the main thread 
void start_conveter() {
	char response;
	int from, to;
	string binary_value, value;
	bool Done = false;
	cout << cout.width(30) << "\bWelcome to Binary and Base Conveter\n" << endl;
	while (not Done) {
		cout << "A. To Create A Table.\n";
		cout << "B. To Change One Base to Another Base.\n>";
		cin >> response;
		response = tolower(response);
		if (response == 'b') {
			cout << "Please Enter Number, From Base, and To Base.\n>";
			cin >> value >> from >> to;
			base_converter(value, from, to);
			cout << endl;
		}
		else if (response == 'a') {
			cout << "Enter number up to X and Y\n>";
			cin >> from >> to;
			create_table(from, to);
		}
		cout << "\nConvert Again? Y/N\n>";
		cin >> response;
		response = toupper(response);
		if (response == 'Y') {
			continue;
		}
		else Done = true;
	}
}


// Takes X and Y values up to given by user and Creates a table in given base
void create_table(int x, int y) {
	string digits;
	int base;
	char type;
	cout << "Enter the Type of Arithmetic you wants to do with two numbers\nA. Add (+).\nB. Multiply (*).\n";
	cin >> type;
	type = tolower(type);
	if (type == 'a' or type == '+') {
		digits = to_string(x + y);
	}
	else if (type == 'b' or type == '*') {
		cout << "Enter X, Y Values to Multiply" << endl;
		digits = to_string(x * y);
	}
	else return;
	cout << "Enter the Base you would like to convert values into\n>";
	cin >> base;
	base_converter(digits, 10, base);
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

// This function takes alphabet letter and return the digits
int getInt(char letter) {
	int number;
	if (letter >= 'A' and letter <= 'Z') {
		number = letter - 55;
		return number;
	}
	return letter;
}

// This function takes a number and from which base you want to convert the number into new base
void base_converter(string number, int from_base, int to_base) {
	int *to_results = NULL;
	int SIZE = number.length() - 1, i = SIZE, from_power = 0, to_tenth_sum = 0, to_placer = 0, power = 0;
	to_results = new int[SIZE];
	if (from_base > 1 and from_base < 37 and to_base > 1 and to_base < 37) {
		while (i > -1) {
			if (from_base > 10 and (number[i]) > 10 and getInt((number[i])) < from_base) {
				cout << getInt((number[i]));
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
