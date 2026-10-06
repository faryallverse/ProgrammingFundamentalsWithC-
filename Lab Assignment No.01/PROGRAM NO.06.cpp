#include <iostream>
using namespace std;
int main()
{
	float attendance;
	char assignment;
	
	cout << "Enter your attendance percentage= ";
	cin >> attendance;
	cout << "\nEnter your assignment submission status(Y/N)= ";
	cin >> assignment;
	
	if(attendance>=75 && assignment=='Y')
		cout << "\nYou're eligible for exams.";
	else
		cout << "\nYou're not eligible for exams.";
}
