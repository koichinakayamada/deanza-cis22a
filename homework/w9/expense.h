/*********************************************************************
* Name: Koichi Nakayamada
* Project: Project 2
* Editor(s) used: VSCode
* Compiler(s) used: g++
* Description: Write a menu-driven program that provides the following options:
1. Show All
2. Spend
3. Search expenses containing this string
4. Search expenses with greater than or equal to this amount
5. Exit
It allows the user to select a menu option to display all expenses, add new entry,
search for a
substring and find the list of entries greater a given amount
**********************************************************************/
#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense
{
private:
    std::string description;
    double amount;

public:
    /*******************************************************************
     * Function: Expense
     * Description: Default constructor
     * Parameters: None
     * Return: None
     *******************************************************************/
    Expense();

    /*******************************************************************
     * Function: Expense
     * Description: Parameterized constructor
     * Parameters: const std::string& desc, double amt
     * Return: None
     *******************************************************************/
    Expense(const std::string &desc, double amt);

    /*******************************************************************
     * Function: setDescription
     * Description: Sets the description of the expense
     * Parameters: const std::string& desc
     * Return: None
     *******************************************************************/
    void setDescription(const std::string &desc);

    /*******************************************************************
     * Function: getDescription
     * Description: Returns the description of the expense
     * Parameters: None
     * Return: std::string
     *******************************************************************/
    std::string getDescription() const;

    /*******************************************************************
     * Function: setAmount
     * Description: Sets the amount of the expense
     * Parameters: double amt
     * Return: None
     *******************************************************************/
    void setAmount(double amt);

    /*******************************************************************
     * Function: getAmount
     * Description: Returns the amount of the expense
     * Parameters: None
     * Return: double
     *******************************************************************/
    double getAmount() const;

    /*******************************************************************
     * Function: containsDescription
     * Description: Checks if the expense description contains a given substring
     * Parameters: const std::string& searchString
     * Return: bool
     *******************************************************************/
    bool containsDescription(const std::string &searchString) const;
};

#endif // EXPENSE_H
