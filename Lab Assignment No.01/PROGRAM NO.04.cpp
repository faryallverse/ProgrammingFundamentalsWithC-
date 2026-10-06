#include <iostream>
using namespace std;
int main()
{
	float CP, SP;
	
	cout << "Enter the cost price: ";
	cin >> CP;
	cout << "Enter the selling price: ";
	cin >> SP;
	
	if(SP>CP)
	{
		cout << "Profit";
	}
	else if(SP<CP)
	{
		cout << "Loss";
	}
	else
	{
		cout << "Neither Profit nor Loss";
	}
}
