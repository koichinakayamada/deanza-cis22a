/*********************************************************************
* Name: Koichi Nakayamada
* Project: PrintExpressionsWithOptions
* Editor(s) used: Xcode
* Compiler(s) used: Xcode
* Description: Write a C++ program named "PrintExpressionsWithOptions" that will read in two positive numbers (integers) and a printing option (character). The printing option can be either 'A' for all expressions ('+', '-', '*', '/', and '%') and 'B' for basic operations ('+' and '-').
 
 It will print out the expression list based on that given printing option.
* This program manages courses taken by a student.
**********************************************************************/

#include <iostream>
#include <iomanip> // Include for setw

int main() {
    // Declare variables
    int operand1, operand2;
    char printingOption;

    // Input operands and printing option
    std::cout << "Please enter the first operand: ";
    std::cin >> operand1;

    if (operand1 < 0) {
        std::cout << "The first operand is not valid." << std::endl;
        return 0;
    }

    std::cout << "Please enter the second operand: ";
    std::cin >> operand2;

    if (operand2 < 0) {
        std::cout << "The second operand is not valid." << std::endl;
        return 0;
    }

    std::cout << "Please enter the printing option ('A' or 'B'): ";
    std::cin >> printingOption;

    // Initialize variables for expressions
    int resultAddition = operand1 + operand2;
    int resultSubtraction = operand1 - operand2;
    int resultMultiplication = operand1 * operand2;
    int resultDivision = operand1 / operand2;
    int resultModulus = operand1 % operand2;

    // Print expressions based on the printing option
    std::cout << std::endl;

    switch (printingOption) {
        case 'A':
            std::cout << std::setw(5) << operand1 << " + " << std::setw(5) << operand2 << " = " << std::setw(5) << resultAddition << std::endl;
            std::cout << std::setw(5) << operand1 << " - " << std::setw(5) << operand2 << " = " << std::setw(5) << resultSubtraction << std::endl;
            std::cout << std::setw(5) << operand1 << " * " << std::setw(5) << operand2 << " = " << std::setw(5) << resultMultiplication << std::endl;
            std::cout << std::setw(5) << operand1 << " / " << std::setw(5) << operand2 << " = " << std::setw(5) << resultDivision << std::endl;
            std::cout << std::setw(5) << operand1 << " % " << std::setw(5) << operand2 << " = " << std::setw(5) << resultModulus << std::endl;
            break;
        case 'B':
            std::cout << std::setw(5) << operand1 << " + " << std::setw(5) << operand2 << " = " << std::setw(5) << resultAddition << std::endl;
            std::cout << std::setw(5) << operand1 << " - " << std::setw(5) << operand2 << " = " << std::setw(5) << resultSubtraction << std::endl;
            break;
        default:
            std::cout << "Unsupported printing option." << std::endl;
    }

    return 0;
}
