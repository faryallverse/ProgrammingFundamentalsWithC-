#include <iostream>
using namespace std;
int main()
{
	int num;
	
	cout << "Enter a number in the range of days of week: ";
	cin >> num;
	
	switch(num)
	{
		case 1:
			cout << "It's MONDAY.";
			break;
		case 2:
			cout << "It's TUESDAY.";
			break;
		case 3:
			cout << "It's WEDNESDAY.";
			break;
		case 4:
			cout << "It's THURSDAY.";
			break;
		case 5:
			cout << "It's FRIDAY.";
			break;
		case 6:
			cout << "It's SATURDAY.";
			break;
		case 7:
			cout << "It's SUNDAY.";
			break;
		default:
			cout << "Invalid input.";
	}
}
