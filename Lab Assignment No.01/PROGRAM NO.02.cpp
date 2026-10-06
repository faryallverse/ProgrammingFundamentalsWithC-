#include<iostream>
using namespace std;
int main()
{
	//Declaring variables
	int n1, n2, n3;
	
	//Taking input
	cout << "Enter an integer number: ";
	cin >> n1;
	cout << "Enter another integer number: ";
	cin >> n2;
	cout << "Enter another integer number: ";
	cin >> n3;
	
	if(n1>n2 && n1>n3)
		cout << n1 << " is the largest number.";
	else if(n2>n1 && n2>n3)
		cout << n2 << " is the largest number.";
	else if(n3>n1 && n3>n2)
	    cout << n3 << " is the largest number.";
    else
        cout << "All numbers are equal.";
}
