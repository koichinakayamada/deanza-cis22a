/*********************************************************************
* Name: Koichi Nakayamada
* Project: computeChange
* Editor(s) used: Xcode
* Compiler(s) used: Xcode
* Description: Modern grocery stores now often have a "U-Scan" checkout lane, allowing the customer
 to scan and check out their own groceries, without the need of a human checker. These
 lanes require that change be provided automatically, after the customer sticks their cash
 in a slot. You are to write a program that computes the bills and coins to be dispensed,
 minimizing the total number of bills and coins. (That is, for change totaling $5.50, you
 should not dispense 5 ones and 50 pennies, but a $5 bill and a 50-cent piece instead.)
 The bills and coins available for you to dispense are as follows: $100 bill, $50 bill, $20
 bill, $10 bill, $5 bill, $1 bill, 50-cent coin, 25-cent coin, 10-cent coin, 5-cent coin, 1-cent
 coin.
 The program prompts the user to input 2 numbers. The first number is the amount of the
 purchase, and the second one is the amount tendered by the customer. You may
 assume that the amount tendered is greater than or equal to the amount of purchase.
 The console output will be a series of lines showing the amount of change returned and
 detailing the number of bills and coins that will be dispensed as change, in descending
 order of monetary amount, one unit per line. If a bill/coin is not needed in the change
 returned, no output is produced for that bill/coin. (In other words, do not display "0 $1
 bills".)
 Plural logic. Proper use of plurals is required, as shown in the sample below. This will
 require some if-else logic to decide whether or not to append an "s" to the end of a
 denomination name.
 Here the sample -- for a purchase of 42.15, the amount tendered is 50. There are no $'s
 or commas in the input -- just positive real numbers that may or may not contain a
 decimal. Here is the output:
 Enter the purchase amount: 42.15
 Enter the tendered amount: 50
 Your change: $7.85
 1 $5 bill
 2 $1 bills
 1 50-cent coin
 1 25-cent coin
 1 10-cent coin
 The program ends normally after the output is produced. Here are some more samples,
 for a purchase of $13.30 and a tender of $15:
 Enter the purchase amount: 13.30
 Enter the tendered amount: 15
 Your change: $1.70
 $1.70
 1 $1 bill
 1 50-cent coin
 2 10-cent coins
* This program manages courses taken by a student.
**********************************************************************/

#include <iostream>
#include <iomanip>

void dispenseChange(double& change, double denomination, const std::string& name);
void printDenomination(int count, const std::string& name);

int main() {
    double purchaseAmount, tenderedAmount;

    // Prompt user for input and validate input
    do {
        std::cout << "Enter the purchase amount: ";
        std::cin >> purchaseAmount;

        std::cout << "Enter the tendered amount: ";
        std::cin >> tenderedAmount;

        if (purchaseAmount < 0 || tenderedAmount < 0 || tenderedAmount < purchaseAmount) {
            std::cout << "Invalid input. Please enter valid amounts." << std::endl;
        }
    } while (purchaseAmount < 0 || tenderedAmount < 0 || tenderedAmount < purchaseAmount);

    // Calculate change with proper formatting
    double change = tenderedAmount - purchaseAmount;
    std::cout << "Your change: $" << std::fixed << std::setprecision(2) << change << std::endl;

    change = round(change * 100);
    
    // Dispense change in bills and coins
    dispenseChange(change, 100.0, "$100 bill");
    dispenseChange(change, 50.0, "$50 bill");
    dispenseChange(change, 20.0, "$20 bill");
    dispenseChange(change, 10.0, "$10 bill");
    dispenseChange(change, 5.0, "$5 bill");
    dispenseChange(change, 1.0, "$1 bill");
    dispenseChange(change, 0.5, "50-cent coin");
    dispenseChange(change, 0.25, "25-cent coin");
    dispenseChange(change, 0.1, "10-cent coin");
    dispenseChange(change, 0.05, "5-cent coin");
    dispenseChange(change, 0.01, "1-cent coin");

    return 0;
}

// Function to dispense change for a particular denomination
void dispenseChange(double& change, double denomination, const std::string& name) {
    int count = 0;
    int intDenomination = static_cast<int>(round(denomination * 100)); // Convert to cents as integer

    while (change >= intDenomination) {
        change -= intDenomination;
        count++;
    }

    // Print only if there are bills or coins to dispense
    if (count > 0 || (intDenomination == 1 && change > 0)) {
        printDenomination(count, name);
    }
}

// Function to print denomination based on count
void printDenomination(int count, const std::string& name) {
    if (count > 0) {
        if (count > 1) {
            std::cout << count << " " << name + "s" << std::endl;
        } else {
            std::cout << count << " " << name << std::endl;
        }
    }
}
