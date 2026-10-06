#include <iostream>
using namespace std;
int main()
{
	int X = 5;
	int password;
	
	for(int i=5;i>0;i--)
	{
		cout << "\nEnter your password: ";
     	cin >> password;
     	
		if(password==4321)
		{
			cout << "\nAccess Granted!";
			return 0;
		}
		else
		{
			X--;
			cout << "\nWrong password. " << X << " attempts left.";
		}
	}
	
	cout << "\nAccount locked! Maximum attempts reached.";
}
