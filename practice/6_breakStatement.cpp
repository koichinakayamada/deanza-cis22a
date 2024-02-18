#include <iostream>
using namespace std;

int main()
{
    const int EMPANADA_COST = 3;
    const int TACO_COST = 4;

    int userMoney;
    int numTacos;
    int numEmpanadas;
    int mealCost;
    int maxEmpanadas;
    int maxTacos;

    mealCost = 0;

    cout << "Enter money for meal: ";
    cin >> userMoney;

    maxEmpanadas = userMoney / EMPANADA_COST;
    maxTacos = userMoney / TACO_COST;

    for (numTacos = 0; numTacos <= maxTacos; ++numTacos)
    {
        cout << "First for loop." << endl;

        for (numEmpanadas = 0; numEmpanadas <= maxEmpanadas; ++numEmpanadas)
        {
            cout << "Second for loop." << endl;

            mealCost = (numEmpanadas * EMPANADA_COST) + (numTacos * TACO_COST);

            // Find first meal option that exactly matches user money
            if (mealCost == userMoney)
            {
                cout << "Inner loop exits." << endl;
                break;
            }
        }

        // If meal option exactly matching user money is found,
        // break from outer loop as well
        if (mealCost == userMoney)
        {
            cout << "Outer loop exits." << endl;
            break;
        }
    }

    if (mealCost == userMoney)
    {
        cout << "$" << mealCost << " buys " << numEmpanadas << " empanadas and " << numTacos << " tacos without change." << endl;
        cout << "Empanadas: $" << EMPANADA_COST * numEmpanadas << endl;
        cout << "Tacos: $" << TACO_COST * numTacos << endl;
    }
    else
    {
        cout << "You cannot buy a meal without having change left over." << endl;
    }

    return 0;
}
