#include <iostream>
using namespace std;

/*
    For loop:
        for (initialExpression; conditionExpression; updateExpression){
            // Loop body
        }
        // Statements after the loop
*/

int main()
{
    double initialSavings; // Use-entered initial savings
    double interestRate; // Interest rate
    double currSavings; // Current savings with interest
    int i; // Loop variable

    cout << "Enter initial savings: ";
    cin >> initialSavings;

    cout << "Enter interest rate in %: ";
    cin >> interestRate;
    interestRate /= 100; 
    // 5% = 5 / 100
    // interestRate /= {interestRate = interestRate / 100}

    currSavings = initialSavings;
    for (i = 0; i < 10; ++i){
        cout << "$" << currSavings << endl;
        currSavings = currSavings + (currSavings * interestRate); // Note: 5% = 5 / 100
    }

    /*
        Difference between pre-increment and post-increment
    */

    // Pre-increment: increment and use the value
    i = 10;
    cout << "Pre-increment: ++i = " << ++i << endl;
    cout << "After the pre-increment: i = " << i << endl;

    // Post-increment: use the value, then increment
    i = 10;
    cout << "Post-increment: i++ = " << i++ << endl;
    cout << "After the post-increment: i = " << i << endl;

    // Same thing for --i, and i--

    return 0;
}
