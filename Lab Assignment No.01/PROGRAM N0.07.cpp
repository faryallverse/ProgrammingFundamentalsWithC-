#include <iostream>
using namespace std;
int main()
{
	string username;
	int password;
	
	cout << "Enter your username= ";
	cin >> username;
	cout << "\nEnter your password= ";
	cin >> password;
	
	if(username=="admin")
	{
		if(password==1234)
			cout << "\nLogin Successful";
		else
			cout << "\nIncorrect Password";
	}
	else 
	{
		cout << "\nInvalid Username";
	}
}
