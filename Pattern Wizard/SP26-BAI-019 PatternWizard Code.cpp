#include <iostream>
using namespace std;
int main()
{
    /*Developer's name: Faryal Sarfraz
    Roll number: SP26-BAI-019
    Program's name: PatternWizard*/

    /*Statement: Write a C++ program that generates different number patterns using loops. The user should be able to choose the pattern type and enter a size
N, where N determines the pattern's height. The user chooses a pattern by entering a number (1-4) and then inputs the size N. The program should validate the input and then print the selected pattern.*/
/*The program should display the following options to the user:
1. Right-Angled Triangle (using for loops)
2. Inverted Triangle (using while loops)
3. Diamond Pattern (using nested for loops)
4. Pyramid Pattern (using do-while loops)*/

/*Input: The type of pattern (1-4) and the height of the pattern (N)
Output: The required pattern with the required height*/

//The Code

cout << "Welcome to the PatternWizard!";
cout << "\nChoose a pattern to display: \n1.Right-Angled Triangle \n2.Inverted Triangle \n3.Diamond \n4.Pyramid";

//Declaring the variables
int choice,N;

//Taking input;
cout << "\nEnter your choice (1-4): ";
cin >> choice;
cout << "\nEnter the height of the pattern: ";
cin >> N;

//The Patterns
switch(choice)
{ //Right-Angled Triangle Pattern
case 1:
	{
      for(int i=1;i<=N;++i)
      {
        for(int j=1;j<=i;++j)
        	cout << j;

		cout << "\n";
      }
      break;
    }
//Inverted Triangle Pattern
case 2:
	{
		int i=N;
		while(i>=1)
		{
			int j=1;
			while(j<=i)
			{
				cout << j;
				++j;
			}
			cout << "\n";
			--i;
		}
		break;
	}
//Diamond Pattern
case 3:
	{//Upper half of the diamond
		for(int i=1;i<=N;i++)
		{
			for(int s=1;s<=N-i;s++)
				cout << " ";
			
			for(int j=1;j<=(2*i-1);j++)
			{
				if(j<=i)
					cout << j;
				else
					cout << (2*i)-j;
			}
	        cout << "\n";
        }
    //Lower half of the diamond
        for(int i=N-1;i>=1;i--)
        {
        	for(int s=1;s<=N-i;s++)
        		cout << " ";

			for(int j=1;j<=(2*i-1);j++)
			{
				if(j<-i)
					cout << j;
				else
					cout << (2*i)-j;
			}
			cout << "\n";
		}
        break;
	}
//Pyramid Pattern
case 4:
	{
		int i=1;
		do{
		    //Spaces
			int j=i;
			do{
				cout << " ";
				j++;
			}while(j<= N);
			
			//Numbers
			int k=1;
			do{
				cout << k;
				k++;
			}while(k<=(2*i-1));
			
			cout << endl;
			i++;
		}while(i<=N);
		break;
	}
default:
	cout << "\nInvalid pattern choice.";
}
}

