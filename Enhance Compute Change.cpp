/*********************************************************************
* Name: Koichi Nakayamada
* Project: Enhance Compute Change
* Editor(s) used: Xcode
* Compiler(s) used: Xcode
* Description: The feature of this program is the same as your  "Compute Change" exercise.  You need to enhance it to use an array to store the bill and coin denomination values (100, 50, 20, 10, 5, etc ...).  As the result of using an array, your code should be simplified.
* This program manages courses taken by a student.
**********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

// Function to dispense change for a given denomination
void dispenseChange(double& change, double denomination, const std::string& name) {
    int count = 0;
    int intDenomination = static_cast<int>(round(denomination * 100)); // Convert denomination to cents

    while (change >= intDenomination) {
        change -= intDenomination; // Subtract denomination from change
        count++; // Increment count of this denomination
    }

    if (count > 0) { // If any denomination is dispensed
        std::cout << count << " " << name << (count > 1 ? "s" : "") << std::endl; // Print the count and denomination
    }
}

int main() {
    double purchaseAmount, tenderedAmount, change;

    // Array of denominations and their names for bills and coins
    double denominations[] = {100.0, 50.0, 20.0, 10.0, 5.0, 1.0, 0.5, 0.25, 0.1, 0.05, 0.01};
    std::string names[] = {"$100 bill", "$50 bill", "$20 bill", "$10 bill", "$5 bill", "$1 bill",
                            "50-cent coin", "25-cent coin", "10-cent coin", "5-cent coin", "1-cent coin"};
    const int SIZE = sizeof(denominations) / sizeof(denominations[0]); // Determine the size of the arrays

    // Prompt for and validate user input
    do {
        std::cout << "Enter the purchase amount: ";
        std::cin >> purchaseAmount;
        std::cout << "Enter the tendered amount: ";
        std::cin >> tenderedAmount;

        if (purchaseAmount < 0 || tenderedAmount < 0 || tenderedAmount < purchaseAmount) {
            std::cout << "Invalid input. Please enter valid amounts." << std::endl;
        }
    } while (purchaseAmount < 0 || tenderedAmount < 0 || tenderedAmount < purchaseAmount);

    // Calculate and display the total change
    change = tenderedAmount - purchaseAmount;
    std::cout << "Your change: $" << std::fixed << std::setprecision(2) << change << std::endl;

    change = round(change * 100); // Convert total change to cents

    // Dispense change using the denominations array
    for (int i = 0; i < SIZE; i++) {
        dispenseChange(change, denominations[i], names[i]); // Call function for each denomination
    }

    return 0;
}
