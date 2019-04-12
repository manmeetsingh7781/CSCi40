// Manmeet Singh
// This program will add up to 100 digits of numbers given by the user

#include <iostream>
using namespace std;

//This program will test three functions capable of reading, adding, 
//and printing 100-digit numbers.

// Do not change these function prototypes:
void readBig(int[]);
void printBig(int[]);
void addBig(int[], int[], int[]);
const int MAX_DIGITS = 100;
// This constant should be 100 when the program is finished.


//There should be no changes made to the main program when you turn it in.
int main()
    {
  	int num1[MAX_DIGITS], num2[MAX_DIGITS], sum[MAX_DIGITS];
    bool done = false;
    char response;
  	while (not done)
	{
		cout << "Please enter a number up to " << MAX_DIGITS << " digits: ";
		readBig(num1);
		cout << "Please enter a number up to " << MAX_DIGITS << " digits: ";
		readBig(num2);
		addBig(num1, num2, sum);
		printBig(num1);
		cout << "\n+\n";
		printBig(num2);
		cout << "\n=\n";
		printBig(sum);
		cout << "\n";
		cout << "test again?";
		cin >> response;
		cin.ignore(900, '\n');
		done = toupper(response) != 'Y';
	}
    return 0;
    
  }


//ReadBig will read a number as a string,
//It then converts each element of the string to an integer and stores it in an integer array.
//Finally, it reverses the elements of the array so that the ones digit is in element zero,ement 1, the hundreds digit is in element 2, etc.
void readBig(int arr[])
{
	string number;
	char temp;
  bool Done = false;
  int start;
  
  // setting each digits in the array to 0
	for (start = 0; start < MAX_DIGITS; start++)
		arr[start] = 0;
		
	// getting value from the user
	cin >> number;

  // getting the size of user value
	start = number.length()-1; 
	
	for(; start >= 0; start--) {
	    // swapping the digits 
     if(not Done){
      temp = number.at(start);
      number.at(start) = number.at((number.length() -1) -start);
      number.at((number.length() -1) - start) = temp;
     }
     if(start == number.length()/2) Done = true;

	}
  // '0' is a char and it's value is 48 so I am subtracting 48 from each digit to get real value out of it 
	for (start = 0; start < number.length(); start++)
    arr[start] = number.at(start)-'0';

}

//PrintBig uses a while loop to skip leading zeros and then uses a for loop to print the number.
void printBig(int num[]) {
	int digit;

  digit = MAX_DIGITS-1;

	while (num[digit] == 0){
		digit--;
  }

	for (; digit > -1; digit--)
		cout << num[digit];

	cout << endl;
}

//AddBig adds the corresponding digits of the first two arrays and stores the answer in the third.
void addBig(int arr1[], int arr2[], int arr3[]){

 	int digit, total,  digit_helper, temp, sum_array_size;
  bool Done = false;
  digit_helper = 0;

  // Setting the sum array values to 0 
	for (digit = 0; digit < MAX_DIGITS; digit++)
		arr3[digit] = 0;


	for (digit = 0; digit < MAX_DIGITS; digit++){
    // Adding up each values from each arrays
		total = arr1[digit] + arr2[digit] + digit_helper;

    // carring the digit to helper and then adding it 
		if (total >= 10){
			 digit_helper = total / 10;
			 total = total % 10;
		} else digit_helper = 0;

  // Pushing each digit the total into the array
	arr3[digit] = total;
	
  }

	sum_array_size = digit;

  while((not Done) and (digit >= 0)) {
 
		temp = arr3[digit];
		arr3[digit] = arr3[sum_array_size - digit];
		arr3[sum_array_size - digit] = temp;
    if(temp == sum_array_size/2) Done = true; 
    digit--;
}
}
