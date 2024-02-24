#include <iostream>
#include <iomanip>
using namespace std;

double computeAverage(int numCount){
    double valuesSum = 0;
    int currValue = 0;

    for (int i = 0; i < numCount; ++i){
        cout << "Enter number: ";
        cin >> currValue;
        valuesSum += currValue; // valueSum = valumSum + currValue
    }
    return valuesSum / numCount;
}

int main(){
    int numValues;
    double averageVal;

    cout << "Enter the number of Values: ";
    cin >> numValues;
    averageVal = computeAverage(numValues);

    cout << "Average: ";
    cout << fixed << setprecision(3) << averageVal << endl;
}