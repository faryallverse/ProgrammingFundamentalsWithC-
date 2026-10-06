#include <iostream>
using namespace std;
int main()
{
	int age;
	char seat;
	int fare = 500;
	
	cout << "Enter your age= ";
	cin >> age;
	cout << "\nEnter your seat preferance(W for window or A for aisle)= ";
	cin >> seat;
	
	//Age Conditions
	if(age<5)
	{
		cout << "\nNo ticket required.";
		return 0;
	}
	else if(age>=5 && age<=12)
	{
		fare = fare/2;	
		cout << "\nHalf fare applied";
	}
	else if(age>60)
	{
		fare = fare*0.70;
		cout << "\nSenior citizen discount applied";
	}
	else
	{
		cout << "\nFull fare applied";
	}
	
	//Seat Preferance Conditions
	if(seat=='W')
	{
		fare += 50;
		cout << "\nWindow seat charge= +50";
	}
	else if(seat=='A')
	{
		cout << "\nNo extra charge";
	}
	else
	{
		cout << "\nInvalid seat preferance.";
	}
	
	cout << "\nYour total fare is $" << fare << ".";
}
