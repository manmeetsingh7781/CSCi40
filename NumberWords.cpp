//  Manmeet Singh
//  This Program will print the numbers into the form of complete english counting words 


#include <iostream>
using namespace std;
// Function Initilizations
void checkSingleDigit(int);
void checkDoubleDigits(int);
void convertNumberToWords(int);

// Declaring the variables for getting the divisors and remainders of the value to make pairs    
int millionSet, thousandSet, hundredSet, first_set, original, firstDigitOfMillion,  first_second, secondSet, secondSetFirstDigit, secondSetLastDigits;

int lastSet, lastSetFirstDigits, lastSetLastDigits, first_of_Five, SingleSecondOfFive, lastOfFive, first_of_four, firstOfEight;


int main ()
{
    // Getting the User input numbers and then plugin these numbers into the function to get the letters
    int user_input;
    cout << "Enter 5 to 9 Digit Numbers \n";
    cin >> user_input;

    // Calling the function for letters;
    convertNumberToWords(user_input);
    cout << endl;
    return 0;
}


// This function convert the number to words 
void convertNumberToWords(int number){
  original = number; 

  cout << "The Number you enter is "<< original << endl;
  if(number == 10000000){
      checkDoubleDigits(number / 1000000 ); 
      cout << " million " << endl;
  }

  else if(number == 100000000){
    checkSingleDigit(number / 100000000);
    checkDoubleDigits(number / 1000000 ); 
    cout << " million " << endl;
  }

  else if(number == 10000) {
    checkDoubleDigits(number/1000);
    cout << " thousand " << endl;
  } 

  else if(number == 100000) {
    checkSingleDigit(number/100000);
    checkDoubleDigits(number/1000);
    cout << " thousand " << endl;
  }

  else if(number == 1000000) {
    checkSingleDigit(number/1000000);
    cout << " million " << endl;
  }

  else { 
    // Temp variables for checking
    millionSet = original;
    thousandSet = original % 1000000;
    hundredSet = thousandSet % 1000;
    if(millionSet > 100000){
        first_set = (original / 1000000) ;
        firstDigitOfMillion = first_set / 100;
        first_second = (first_set % 100);
        if(millionSet >= 100000000){
            checkSingleDigit(firstDigitOfMillion);
            cout << "hundred ";
        }
        if(thousandSet > 100000){
        if(first_second <= 10 and first_second > 0){
            checkSingleDigit(first_second);
            cout << "million ";
        }
        else if (first_second >= 10){
            checkDoubleDigits(first_second);
            cout << "million ";
          }
      }
   }
    if(thousandSet > 100000)
    {
      secondSet = (original / 1000) % 1000;
      secondSetFirstDigit =  (secondSet / 100);
      secondSetLastDigits =  (secondSet % 100);
      if(thousandSet > 10000){
          checkSingleDigit(secondSetFirstDigit);
          cout << "hundred ";
          checkDoubleDigits(secondSetLastDigits);
          cout << "thousand ";
        }
    }
    if(original > 10000 and original < 100000) {
        first_of_Five = original / 1000;
        checkDoubleDigits(first_of_Five);
        cout << "thousand ";
        SingleSecondOfFive = (original % 1000) / 100;
        checkSingleDigit(SingleSecondOfFive);
        cout << "hundred ";
        lastOfFive = (original %  100) ;
        checkDoubleDigits(lastOfFive);
    }
    if (hundredSet < 10000 and original > 100000){
          lastSet = original % 1000;
          lastSetFirstDigits = lastSet / 100;
          lastSetLastDigits = lastSet % 100;
          checkSingleDigit(lastSetFirstDigits);
          cout << "hundred ";
          checkDoubleDigits(lastSetLastDigits);
    }
  }
}

// Gets the single digit number and return the English letter 
void checkSingleDigit(int singleDigit){
  switch(singleDigit){
   
   case 1:
   cout <<  "one ";
   break;
            
   case 2:
   cout <<  "two ";
   break;
            
   case 3:
   cout <<  "three ";
   break;
            
   case 4:
   cout <<  "four ";
   break;
            
   case 5:
   cout <<  "five ";
   break;
            
   case 6:
   cout <<  "six ";
   break;
            
   case 7:
   cout << "seven ";
   break;
           
   case 8:
   cout << "eight ";
   break;
            
   case 9:
   cout <<  "nine ";
   break;
   }
}

// Takes double Digits and returns the English letters
void checkDoubleDigits(int twoDigits){
  switch(twoDigits) {
    case 10:
    cout << " ten ";
    break;
    
    case 11:
    cout<< "eleven ";
    break;
    
    case 12:
    cout<< "twelve ";
    break;
    
    case 13:
    cout<< "thirteen ";
    break;
    
    case 14:
    cout<< "fourteen ";
    break;
    
    case 15:
    cout<< "fifteen ";
    break;
    
    case 16:
    cout<< "sixteen ";
    break;
    
    case 17:
    cout<< "seventeen ";
    break;
    
    case 18:
    cout<< "eighteen ";
    break;
    
    case 19:
    cout<< "nineteen ";
    break;
  
    case 20 ... 29:
    cout << " twenty ";
    checkSingleDigit(twoDigits%10);   
    break;
    
    case 30 ... 39:
    cout<< "thirty ";  
    checkSingleDigit(twoDigits%10);         
    break;

    case 40 ... 49:
    cout<< "forty "; 
    checkSingleDigit(twoDigits%10);   
    break;

    case 50 ... 59:
    cout<< "fifty ";
    checkSingleDigit(twoDigits%10);   
    break;
    
    case 60 ... 69:
    cout<< "sixty ";
    checkSingleDigit(twoDigits%10);   
    break; 

    case 70 ... 79:
    cout<< "seventy ";   
    checkSingleDigit(twoDigits%10);                 
    break;

    case 80 ... 89:
    cout<< "eighty ";
    checkSingleDigit(twoDigits%10);   
    break;
    
    case 90 ... 99:
    cout<< "ninety  ";  
    checkSingleDigit(twoDigits%10);    
    break;

    case 100:
    cout << "hundred ";
    checkSingleDigit(twoDigits%10);   
    break;

    default:
    break;
  }
}
