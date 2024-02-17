/*********************************************************************
* Name: Koichi Nakayamada
* Project: Week 2 - Day 1: Print Receipt
* Editor(s) used: Xcode
* Compiler(s) used: Xcode
* Description: Write a C++ program named "PrintReceipt" that will ask the user for the following info:
 - name of the item to be purchased (string)
 - price for each item (double)
 - how many items (integer) to be purchased
 - is this a gift purchase (char)
 - purchase occasion description (string)

 The program will print out the formatted receipt with 10% tax added to the total.
* This program manages courses taken by a student.
**********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Declarations
    string itemName;
    double itemPrice;
    int itemCount;
    char isGift;
    string occasion;

    // Input
    cout << "Enter the name of the item to be purchased: ";
    getline(cin, itemName);

    cout << "Enter the price for each item: $";
    cin >> itemPrice;

    cout << "Enter how many items to be purchased: ";
    cin >> itemCount;

    cout << "Is this a gift purchase? (Y/N): ";
    cin >> isGift;

    cin.ignore(); // Clear buffer
    cout << "Enter purchase occasion description: ";
    getline(cin, occasion);

    // Calculations
    double subtotal = itemPrice * itemCount;
    double tax = 0.1 * subtotal;
    double total = subtotal + tax;

    // Output
    cout << fixed << setprecision(2); // Set precision for currency format

    // Receipt
    cout << "\n************ Receipt ************\n";
    cout << setw(30) << left << "Item Name:" << setw(10) << right << itemName << endl;
    cout << setw(30) << left << "Price per Item:" << setw(10) << right << "$" << itemPrice << endl;
    cout << setw(30) << left << "Number of Items:" << setw(10) << right << itemCount << endl;
    cout << setw(30) << left << "Subtotal:" << setw(10) << right << "$" << subtotal << endl;
    cout << setw(30) << left << "Tax (10%):" << setw(10) << right << "$" << tax << endl;
    cout << setw(30) << left << "Total:" << setw(10) << right << "$" << total << endl;

    // Gift information
    cout << "\nGift Purchase: " << (isGift == 'Y' || isGift == 'y' ? "Yes" : "No") << endl;
    cout << "Occasion: " << occasion << endl;

    cout << "\n*********************************\n";

    return 0;
}
