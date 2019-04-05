// Manmeet Singh
// This program prints a Perfect, Abundent, and Deficient numbers given by users value

#include <iostream>
using namespace std;

void isPerfect(int, bool);
void isAbundent(int, bool);
void isDeficient(int, bool);
void getTotalPercentage();

int const LIMIT = 5000;
double total_perfect, total_abdundent, total_deficient;

int main()
{
    // This function takes Type of number user and prints the Numbers up to limit, 
    // and also user can turn on or off the print to screen letters
   isPerfect(LIMIT, true);
   cout << endl;
   
   isAbundent(LIMIT, true);
   cout << endl;
   // This function calculates the total Percentage of Numbers
   getTotalPercentage();

   cout << endl;
   return 0;
}

// Checks if the number is perfect
void isPerfect(int to, bool print ){
    
    int startChecking, start_point, sum;
    total_perfect = 0;

    // print numbers to screen 
    if(print)
      cout << "What numbers below " << LIMIT << " are perfect?\n";
    

    for(start_point  = 1; start_point <= to; start_point++){
        // Every Number will have its different sum
        sum = 0;
      
      // Start checking the perfect number 
        for(startChecking = 1; startChecking <= start_point/2; startChecking++){
                if(start_point % startChecking == 0)
                    // Adding Dividors 
                    sum += startChecking;
            }
            // Checks the sum of the number;
            if(sum == start_point){
                total_perfect++;
                if(print)
                  cout << start_point << endl;
          } 
    }
}

// Checks if the number is Abundent
void isAbundent(int to, bool print ){
    int startChecking, start_point, sum;
    total_abdundent = 0;

    if(print)
      cout << "What odd numbers below "<< LIMIT <<" are abundant?\n";
    
    for(start_point  = 1; start_point <= to; start_point+=2){
        // Every Number will have its different sum
        sum = 0;
      // Start checking the perfect number 
        for(startChecking = 1; startChecking <= start_point/2; startChecking++){
                if(start_point % startChecking == 0)
                    // Adding Dividors 
                    sum += startChecking;
            }
            // Checks the sum of the number;
           if(sum > start_point){
              total_abdundent++;
               if(print)
                cout << start_point << endl; 
           }
    }
}

// checks if the number is Deficient
void isDeficient( int to, bool print ){

    int startChecking, start_point, sum;
    total_deficient = 0;
    if(print)
      cout << "The Deficient Numbers are below " << LIMIT << " : " ;
    for(start_point  = 1; start_point <= to; start_point++){
      
        // Every Number will have its different sum
        sum = 0;
      // Start checking the perfect number 
        for(startChecking = 1; startChecking <= start_point/2; startChecking++){
                if(start_point % startChecking == 0)
                    // Adding Dividors 
                    sum += startChecking;
            }
            // Checks the sum of the number;
        if (sum < start_point){
                total_deficient++;
         if(print)
                cout << start_point << endl;
        }
    }
}

// This function calculates the total Percentage of Numbers
void getTotalPercentage(){

    // calling the functions and gathering information
    isPerfect(LIMIT, false);
    isAbundent(LIMIT, false);
    isDeficient(LIMIT,false);

    // calculates the total
    total_perfect = (total_perfect/LIMIT)*100;
    total_abdundent = (total_abdundent/LIMIT)*100;
    total_deficient = (total_deficient/LIMIT)*100;

    // prints the total to screen
    cout << "The Percentage of Numbers are: \n";
    cout << "Perfect: " << total_perfect <<"%" << "\nAbundant: " <<  total_abdundent <<"%"<< "\nDeficient: " << total_deficient <<"%" << endl;
}
