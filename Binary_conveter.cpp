// Manmeet Singh
// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void base_converter(int, int);
void base_converter(int, int, int);
unsigned long long int binary_to_decimal(string binary);

int main()
{
	base_converter(4500, 10, 16);
	cout << endl;
	return 0;
}
// Takes a Binary and convert it into the decimal
unsigned long long int binary_to_decimal(string binary) {
	string digits = binary;
	int start = digits.length()-1, each_number = 0, temper = 0, power = 0;
	unsigned long long int sum = 0; 
	while (start >= 0) {
		each_number = static_cast<int>(digits[start] - '0');
		temper = static_cast<int>(each_number * pow(2, power++));
		sum += temper;
		start--;
	}
	return sum;
}
// Takes a Decimal Number and converts the Base 2 upto 11
void base_converter(int digits, int base) {
	if (base > 1 and base < 37) {
		int my_base = digits, start = 0, printer;
		int results[100];
		while (my_base != 0) {
			results[start] = my_base % base;
			start++;
			my_base /= base;
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
void base_converter(int number, int from_base, int to_base) {
	if (from_base > 1 and from_base < 37 and to_base > 1 and to_base < 37) {
		int to_placer = 0, power = 0, answer = 0;
		int to_results[10];
		while (number != 0) {
			answer += static_cast<int>(number % 10 * pow(from_base, power++));;
			number /= 10;
		}
		cout << "The answer is " << answer << endl;
		while (answer != 0) {
			to_results[to_placer++] = answer % to_base;
			answer /= to_base;
		}
		for (power = to_placer - 1; power >= 0; power--) {
			cout << to_results[power];
		}
	}
	else { cout << "Base Limit has been exceeded, please try between 2 and 36\n" << endl;  exit(-1); }
}
