// Manmeet Singh
// This program calls itself to solve its problem

#include <iostream>
#include <limits.h>
using namespace std;

// Function prototypes
int factorial(int);
int GCF(int, int);

int main() {
  unsigned userVal1, userVal2;
  // GCF 
  cout << "Enter Two numbers to find the GCF \n";
  cin >> userVal1 >> userVal2;
  cout << "GFC of " << userVal1 <<  " and " << userVal2 << " is " <<GCF(userVal1, userVal2) << endl;

  // Factorial 
  cout << "\nEnter the Number for Factorial\n";
  cin >> userVal1;
  cout << "Factorial of " << userVal1 << " is " ;
  cout << factorial(userVal1);
  cout << endl;
  return 0;
}

//function finds the factor of given number
int factorial(int number)
{
	if (number == 0)
		number = 1;
    
  else{
  if (factorial(number - 1) > (INT_MAX / number))
	number = 0;
   else number = factorial(number - 1)*number;
}
return number;
}

// function finds the greates common factor of given two numbers 
int GCF(int divider1, int divider2) {
  int result;
  if(divider1 == 0){
    result = divider2;
  } else if(divider2 == 0) result = divider1;
  else {
    result = GCF(divider2, divider1%divider2);
  }
  return result;
}
