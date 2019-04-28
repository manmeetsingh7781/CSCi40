// Manmeet Singh
// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int binary_to_decimal(string);
void base_converter(int, int);
void base_converter(int, int, int);
void recognize_character(int);

int main()
{
	cout << binary_to_decimal("101011100") << endl;
	base_converter(1, 1, 6);
	cout << endl;
	return 0;
}

// Takes a Binary and convert it into the decimal
int binary_to_decimal(string binary) {
	string digits = binary;
	int start = digits.length() - 1, each_number = 0, sum = 0, temper = 0, power = 0;
	while (start >= 0) {
		each_number = static_cast<int>(digits[start] - '0');
		temper = static_cast<int>(each_number * pow(2, power++));
		sum += temper;
		start--;
	}
	return sum;
}

// Take a Decimal Number and converts the Base 2 upto 11
void base_converter(int digits, int base) {
	if (base > 1 and base < 37) {
		int my_base = digits, start = 0, remainder = 0, temp = 0, printer;
		int results[100];
		while (my_base != 0) {
			temp = my_base;
			remainder = temp % base;
			my_base /= base;
			results[start] = remainder;
			start++;
		}
		for (printer = start - 1; printer >= 0; printer--) {
			int digit;
			digit = results[printer];
			cout << digit;
		}
	}
	else { cout << "Base Limit has been exceeded, please try between 2 and 36\n" << endl;  exit(-1); }
}

// This function takes a number and from which base you want to convert the number into new base
void base_converter(int number, int from_base , int to_base) {
	
	if (from_base > 1 and from_base < 37 and to_base > 1 and to_base < 37) {
		int from_remainder = 0, to_placer = 0, value = 0, power = 0, answer = 0, to_remainders = 0;
		int to_results[10];
		while (number != 0) {
			from_remainder = number % 10;
			value = static_cast<int>(from_remainder * pow(from_base, power++));
			answer += value;
			number /= 10;
		}
		cout << "The answer is " << answer << endl;
		while (answer != 0) {
			to_remainders = answer % to_base;
			to_results[to_placer++] = to_remainders;
			answer /= to_base;
		}

		for (power = to_placer - 1; power >= 0; power--) {
			cout << to_results[power];
		}
	}
	else { cout << "Base Limit has been exceeded, please try between 2 and 36\n" << endl;  exit(-1); }
}

void recognize_character(int &digit) {
	cout << &digit << endl;
}
