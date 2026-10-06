/*Faryal Sarfraz (SP26-BAI-019)
Proframming Fundamentals
Assignment no.03
Student Marks Analyzer*/

#include <iostream>
using namespace std;

const int MAX=100;

//User-defined Function Prototypes
int TOTAL(int marks[][MAX], int row, int m);
void subject(int marks[][MAX], int n, int m);
void highLow(int marks[][MAX], int n, int m);

int main()
{
	int n, m;
	int marks[MAX][MAX];
	
	cout << "Enter total students= ";
	cin >> n;
	cout << "Enter total subjects= ";
	cin >> m;
	
	//Taking marks from the user
	for(int i=0; i<n; i++)
	{
		cout << "\nStudent " << i+1 << " marks= \n";
		for(int j=0; j<m; j++)
		{
			cout << " Subject " << j+1 << "= ";
			cin >> marks[i][j];
		}
	}
 
    //Displaying marks
    cout << "\n-- Marks Table --\n";
    for(int i=0; i<n; i++)
    {
	    cout << "Student " << i+1 << ": ";
        for(int j=0; j<m; j++)
    	{
    		cout << marks[i][j] << " ";
    	}
 	cout << endl;
    }

    //Every Student's Total Marks
    cout << "\n-- Student Report --\n";
    for(int i=0; i<n; i++)
    {
        int total = TOTAL(marks, i, m);
  	    cout << "Student " << i+1 << " | Total= " << total << " | Average= " << total/m << endl;
    }
    
    subject(marks, n, m);
    highLow(marks, n, m);
    
    return 0;
}

//Function Definitions

int TOTAL(int marks[][MAX], int row, int m)
{
	int total=0;
	for(int j=0; j<m; j++)
	{
		total += marks[row][j];
	}
	return total;
}

void subject(int marks[][MAX], int n, int m)
{
	cout << "\n-- Subject-Wise Report --\n";
	for(int j=0; j<m; j++)
	{
		int sum=0;
		for(int i=0; i<n; i++)
		{
			sum += marks[i][j];
		}
		cout << "Subject " << j+1 << " | Total= " << sum << " | Average= " << sum/n << endl;
	}
}

void highLow(int marks[][MAX], int n, int m)
{
	int high=marks[0][0], low=marks[0][0];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(marks[i][j] > high)
			{
				high=marks[i][j];
			}
			if(marks[i][j] < low)
			{
				low=marks[i][j];
			}
		}
		cout << "\nHighest= " << high << " | Lowest= " << low << endl;
	}
}
