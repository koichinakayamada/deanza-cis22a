#include <iostream>
#include <iomanip>
using namespace std;

void computeSumAndAverage (int numCount, double &sum, double &average){
    int currValue = 0;

    sum = 0;
    for (int i = 0; i < numCount; ++i) {
        cout << "Enter number: ";
        cin >> currValue;
        sum += currValue;
    }

    average = sum / numCount;
}

int main(){
    int numValues;
    double averageVal, sumVal;

    cout << "Enter number of Values: ";
    cin >> numValues;
    computeSumAndAverage(numValues, sumVal, averageVal);

    cout << "Sum: " << fixed << setprecision(2) << sumVal << endl;
    cout << "Average: " << fixed << setprecision(3) << averageVal << endl;
    return 0;
}