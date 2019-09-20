#include <iostream>
using namespace std;


int main()
{    
    int original , temp, ones, ones1, ones2, ones3, temp2 , temp3 , thous, thous1, thous2, thous3, mills;
    
    cout << "Enter 7 to 9 number: ";
    cin >> original;
    
    temp = original/1000;
    ones = original%1000;
    
    temp2 = ones/10;
    ones1 = ones%10;
    ones2 = temp2%10;
    ones3 = temp2/10;
    
    mills = temp/1000;
    thous = temp%1000;
    
    temp3 = thous/10;
    thous1 = thous%10;
    thous2 = temp3%10;
    thous3 = temp3/10;
    
    cout << "With Commas: \n";
    cout << mills << ","<<thous3 << thous2 << thous1 <<"," << ones3 << ones2 << ones1 << endl;

    return 0;
}





