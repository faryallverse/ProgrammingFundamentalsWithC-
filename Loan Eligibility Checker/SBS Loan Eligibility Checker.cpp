#include <iostream>
using namespace std;
int main()
{
    /* Developer's Name: Faryal Sarfraz
    Roll Number: SP26-BAI-019
    Program's Name: Loan Eligibility Checker */
    
    /* Develop a Smart Banking System that determines whether a customer is eligible for a loan based on multiple conditions using selection structure statements, */
    
    /* Input: User's Name, Age, Monthly Income, and Credit Score
    Output: Display whether the user is eligible for loan or not; if yes, the amount of loan the user is eligible for. */
    
    /* Test Cases:
    1- Customer is ineligible due to age.
    2- Customer is eligible for full loan.
    3- Customer gets reduced loan due to credit score.
    4- Customer is ineligible due to low credit score.
    5- Customer is ineligible due to low income. */
    
    // Variable Declaration
    string name;
    int age,income,credit;
    int loan;
    
    cout << "Welcome to the Loan Eligibility Checker for Smart Banking System!";
    
    //Asking user for input.
    cout << "\nEnter your name: ";
    cin >> name;
    cout << "\nEnter your age: ";
    cin >> age;
    cout << "\nEnter your monthly income in dollars: ";
    cin >> income;
    cout << "\nEnter your credit score: ";
    cin >> credit;
    
    //Checking the conditions.
    if(age>=21 && age<=60)
    {
        if(income<2000)
        {
          cout << "\nSorry, " << name << "! You are not eligible for the loan due to low income.\nThankyou for using the Smart Banking System!";
        }
        else if(income>=2000 && income<=5000)
        {
            loan=10000;
            if(credit<600)
            {
                cout << "\nSorry, " << name << "! Your credit score is too low to qualify for a loan.\nThankyou for using the Smart Banking System!";
            }
            else if(credit>=600 && credit<=750)
            {
                loan = loan*0.50;
                cout << "\nCongratulations, " << name << "! You are aligible for a loan of $" << loan << ".\nThankyou for using the Smart Banking System!";
            }
            else if(credit>750)
            {
                cout << "\nCongratulations, " << name << "! You are eligible for a loan of $" << loan << ".\nThankyou for using the Smart Banking System!";
            }
        }
        else if(income>5000)
        {
            loan=25000;
            if(credit<600)
            {
                cout << "\nSorry, " << name << "! Your credit score is too low to qualify for a loan.\nThankyou for using the Smart Banking System!";
            }
            else if(credit>=600 && credit<=750)
            {
                loan = loan*0.50;
                cout << "\nCongratulations, " << name << "! You are aligible for a loan of $" << loan << ".\nThankyou for using the Smart Banking System!";
            }
            else if(credit>750)
            {
                cout << "\nCongratulations, " << name << "! You are eligible for a loan of $" << loan << ".\nThankyou for using the Smart Banking System!";
            }
        }
    }
    else
    {
        cout << "\nSorry, " << name << "! You are not eligible for the loan due to your age.\nThankyou for using the Smart Banking System!";
    }
    return 0;

}
