// Manmeet Singh
// This function calculates the prices of gas and Electric therms 

#include<iostream>
using namespace std;

// Function prototype
double price(double, double, double, double, double);

int main()
{
    
    double start_point, end_point, total_amount;
    cout << "Enter the start point and end point for Electric:";
	cin >> start_point >> end_point;
	
	
	total_amount = price(start_point, end_point, 238.7, 0.094, 0.133);


	cout << total_amount << endl;
    
    // Resetting the start and end points to reuse 
    start_point = 0; end_point = 0;
    
    cout << "Enter the start point and end point for Gas :";
	cin >> start_point >> end_point;
	
	total_amount = price(start_point, end_point, 31, 0.504, 0.824);

	cout << total_amount << endl;
	
	return 0;
}


double price(double start_point, double end_point, double baseline_quantities, double baseline, double over_baseline_price) {

	double  amount, total, over_quantities;
	
	// Getting the center value of user input from start to end
	total = end_point - start_point;
	
	if (total <= baseline_quantities)
		amount = total * baseline;
	
	else
	{
		over_quantities = total - baseline_quantities;
		amount = (baseline_quantities*baseline) + over_quantities * over_baseline_price;
	}
	return amount;
}

