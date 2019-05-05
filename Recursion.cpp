// Manmeet Singh
// In this CPP file I am using functions that calls themselves to solve thier problems like finding the Greates common factor of two numbers and finding the factors of the given number 

#include <iostream>
#include <limits.h>
using namespace std;

// Function prototypes
int factorial(int);
int GCF(int, int, int, int, int);

int main() {
  unsigned int start = 1, greatest_cm, temp_gcf, userVal1, userVal2;
  // GCF 
  cout << "Enter Two numbers to find the GCF \n";
  cin >> userVal1 >> userVal2;
  cout << "GFC of " << userVal1 <<  " and " << userVal2 << " is " <<GCF(userVal1, userVal2, start, greatest_cm, temp_gcf) << endl;

  // Factorial 
  cout << "\nEnter the Number for Factorial\n";
  cin >> userVal1;
  cout << "Factorial of " << userVal1 << " is " ;
  cout << factorial(userVal1);
  cout << endl;
  return 0;
}

//function takes one number and gets the factor of it until the number is less then 1
int factorial(int number)
{
	if (number == 0)
		number = 1;
  else{
  if (factorial(number - 1) > (INT_MAX / number))
			number = 0;
	else
			number = factorial(number - 1)*number;
	}
	return number;
}

// This function takes number one and two and then where to start and gcf holder to avoid variable re-declaration in recursion
int GCF(int divider1, int divider2, int start, int gcf, int temp) {
  if(divider1 <= 0 or divider2 <= 0){
    return divider1 + divider2;
  }
	if (start != (divider1+1) and start != (divider2+1)) {
      if(divider2 % start == 0 and divider1 % start == 0){
        gcf = start;
        temp = gcf; 
      }
    start +=1;
    return GCF(divider1, divider2, start, gcf, temp);
  }
  cout << "GCF is ";
  return gcf;
}
