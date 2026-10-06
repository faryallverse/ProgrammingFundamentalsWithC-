#include <iostream>
using namespace std;
int main()
{
	int score,total = 0,rounds = 0,choice;
	
	do{
		cout << "\nEnter your score(1-100): ";
		cin >> score;
		
		total += score;
		rounds++;
		
		if(rounds<5)
		{
		cout << "\nDo you want to play another round?(1=YES, 0=NO) ";
		cin >> choice;
    	}
		else
		{
			choice = 0;
		}
	}while(choice==1 && rounds<5);
	
	double average = (double)total/rounds;
	
	cout << "\nQuiz game ends!";
	cout << "\nTotal score: " << total;
	cout << "\nAverage score: " << average;
}
