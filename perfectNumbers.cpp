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
   
   // This function calculates the total Percentage of Numbers
   getTotalPercentage();
   
   return 0;
}

void isPerfect(int to, bool print ){
    
    int startChecking, start_point;

    bool isDivisible;
    if(print){
    cout << "What numbers below " << LIMIT << " are perfect?\n";
    }
    for(start_point  = 1; start_point <= to; start_point++){
      
        // Every Number will have its different sum
        int sum = 0;
        
      // Start checking the perfect number 
        for(startChecking = 1; startChecking <= start_point/2; startChecking++){
                isDivisible = start_point % startChecking;
                if(not isDivisible){
                    // Adding Dividors 
                    sum += startChecking;
                }
            }
            // Checks the sum of the number;
            if(sum == start_point){
                if(print){
                    cout << start_point << endl;
                }
                total_perfect+=1;
                
            } 
    }
}


void isAbundent(int to, bool print ){
     
    int startChecking, start_point;

    bool isDivisible;
    if(print){
    cout << "What odd numbers below "<< LIMIT <<" are abundant?\n";
    }
    for(start_point  = 1; start_point <= to; start_point+=2){
        // Every Number will have its different sum
        int sum = 0;
      // Start checking the perfect number 
        for(startChecking = 1; startChecking <= start_point/2; startChecking++){
                isDivisible = start_point % startChecking;
                if(not isDivisible){
                    // Adding Dividors 
                    sum += startChecking;
                }
            }
            
            // Checks the sum of the number;
           if(sum > start_point){
                total_abdundent+=1;
               if(print){
                cout << start_point << endl;
            }
               
           }
    }
}


void isDeficient( int to, bool print ){
    int startChecking, start_point;
    bool isDivisible;
    if(print){
    cout << "The Deficient Numbers are below " << LIMIT << " : " ;
    }
    for(start_point  = 1; start_point <= to; start_point++){
      
        // Every Number will have its different sum
        int sum = 0;
      // Start checking the perfect number 
        for(startChecking = 1; startChecking <= start_point/2; startChecking++){
                isDivisible = start_point % startChecking;
                if(not isDivisible){
                    // Adding Dividors 
                    sum += startChecking;
                    
                }
            }
            // Checks the sum of the number;
        if (sum < start_point){
                total_deficient+=1;
         if(print){
                cout << start_point << endl;
            }
                
        }
    }
}

// This function calculates the total Percentage of Numbers
void getTotalPercentage(){
    isPerfect(LIMIT, false);
    isAbundent(LIMIT, false);
    isDeficient(LIMIT,false);
    total_perfect = (total_perfect/LIMIT)*100;
    total_abdundent = (total_abdundent/LIMIT)*100;
    total_deficient = (total_deficient/LIMIT)*100;
    cout << "The Percentage of Numbers are: \n";
    cout << "Perfect: " << total_perfect <<"%" << "\nAbundant: " <<  total_abdundent <<"%"<< "\nDeficient: " << total_deficient <<"%" << endl;
}
