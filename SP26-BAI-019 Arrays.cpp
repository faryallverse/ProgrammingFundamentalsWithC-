#include <iostream>
using namespace std;
int main()
{
	int size;
	
	do{
		cout << "\nEnter the size of your array: ";
    	cin >> size;
    	
    	if(size<=0)
    		cout << "\nInvalid input! Enter a positive integer: ";
	}while(size <= 0);
		
	int array[size];
	
	for(int i=0; i<size; i++)
	{
		cout << "\nEnter your element: ";
		cin >> array[i];
	}
    
    int max = array[0];
    for(int i=1; i<size; i++)
    {
    	if(array[i] > max)
    		max = array[i];
	}
	
	cout << "\nMaximum value: " << max;
	cout << "\nMaximum value found at index/indices: ";
	for(int i=0;i<size;i++)
	{
		if(array[i] == max)
			cout << i << " ";
	}
	
	int min = array[0];
    for(int i=1; i<size; i++)
    {
    	if(array[i] < min)
    		min = array[i];
	}
	
	cout << "\nMinimum value: " << min;
	cout << "\nMinimum value found at index/indices: ";
	for(int i=0; i<size; i++)
	{
		if(array[i] == min)
			cout << i << " ";
	}
}
