#include <iostream>
using namespace std;

// function prototype
char getKeyword(int);

int main()
{

  int user_input;
  char letter;

  cout << " Enter Eight digits number \n";
  
  cin >> user_input;
  
  cout <<  user_input << " " << getKeyword(user_input) << endl;
  
  return 0;
}


// Getting the sum of all the values of user input 
char getKeyword(int user_value){
    
    
  int a, b, c, d, a_result, b_result, c_result, d_result, sum;
  

  
  // Dropping the last two digits and storing in the variables 
  a = user_value; 
  b = user_value/100; 
  c = b/100;
  d = c/100;
   
  // Getting the remainder of the digits
  a_result = a % 100;
  b_result = b % 100;
  c_result = c % 100;
  d_result = d % 100;
 
  sum = a_result + b_result + c_result + d_result;
  return 'A' + sum % 26;
}






