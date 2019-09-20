//Manmeet Singh
// This program will get input integers from user and print it with the commas

#include <iostream>
using namespace std;


int main()
{

    int original , temp, ones, ones1, ones2, temp2 , temp3 , thous, thous1, thous2, mills;
    
    cout << "Enter 4 to 6 number: ";
    cin >> original;
    
    temp = original/100;
    ones = original%100;
    
    temp2 = ones/10;
    ones1 = ones%10;
    ones2 = temp2%10;
    
    mills = temp/100;
    thous = temp%100;
    
    temp3 = thous/10;
    thous1 = thous%10;
    thous2 = temp3%10;
    
    cout << "With Commas: \n";
    cout << mills << ","<< thous2 << thous1 <<"," <<  ones2 << ones1 << endl;

    return 0;
}













