// Manmeet Singh
// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int binary_to_ten(string);
void base_converter(int, int);

int main()
{
	cout << binary_to_ten("101011100") << endl;
	base_converter(348, 2);
	cout << endl;
	return 0;
}

// Takes a Binary and convert it into the decimal
int binary_to_ten(string binary) {
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
	int my_base = digits,  start = 0, answer =  0, remainder = 0, temp = 0, printer;
	string results[100];

	while (my_base != 0) {
		temp = my_base;
		answer = temp /base;
		remainder = temp % base;
		my_base /= base;
		results[start] = remainder + '0';
		start++;
	}
	for (printer = start; printer >= 0; printer--) {
		cout << results[printer];
	}
}
