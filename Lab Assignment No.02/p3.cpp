#include <iostream>
using namespace std;
int main()
{
	double m1,m2,m3,m4,m5,percentage;
	
	cout << "\nEnter your marks in subject no.01= ";
	cin >> m1;
	cout << "\nEnter your marks in subject no.02= ";
	cin >> m2;
	cout << "\nEnter your marks in subject no.03= ";
	cin >> m3;
	cout << "\nEnter your marks in subject no.04= ";
	cin >> m4;
	cout << "\nEnter your marks in subject no.05= ";
	cin >> m5;
	
	double marks_obtained = m1 + m2 + m3 + m4 + m5;
	percentage = (marks_obtained/500)*100;
	
	if(percentage>=80)
		cout << "\nYou got grade \'A\'";
	else if(percentage>=60)
		cout << "\nYou got grade \'B\'!";
	else if(percentage>=50)
		cout << "\nYou got grade \'C\'!";
	else
			cout << "\nYou failed!";
}
