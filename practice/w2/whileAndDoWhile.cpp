#include <iostream>
using namespace std;

int main()
{
    int age;
    int currValue, valueSum, numValues;

        cout << "How old are you?: " << endl;
        cin >> age;

    while (age <= 0) {
        cout << "Invalid input, age must be > 0.\n";
        cout << "Enter your age again.\n";
        cin >> age;
    }       

    cout << "Your age: " << age << endl;

    /*  
        Outputs average of list of positive intergers.
        List ends with 0 (sentinel)
        Ex: 10 1 6 3 0 yield (10 + 1 + 6 + 3) / 4, or 5
    */

    cout << "Enter positive values or 0 to terminate: " << endl;
    cin >> currValue;

    while (currValue > 0) {
        valueSum += currValue;  // valuesSum - valuesSum +currValue
        numValues++;    // numvalues = numvalues + 1

        cout << "Enter a positive value or 0 terminate: " << endl;
        cin >> currValue;
    }
    cout << "Average: " << (valueSum / numValues) << endl;

    /*  
        Re-write the age problem using do-while
    */

   /*
        do {
            //loop body
        } while (loopExpression);    
        }
    */

   cout << "Using do-while for age problem: \n";

   do {
        cout << "Enter you age: " << endl;
        cin >> age;
   } while (age <= 0);
   
    cout << "your age: " << age << endl;
    cout << "\nEnd of program." << endl;

}
