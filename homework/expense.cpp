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
#include "expense.h"
#include <algorithm>
#include <cctype>
#include <iostream>

/*******************************************************************
 * Function: Expense (Default Constructor)
 * Description: Initializes an expense object with default values.
 * Parameters: None
 * Return: None
 *******************************************************************/
Expense::Expense() : description(""), amount(0.0) {}

/*******************************************************************
 * Function: Expense (Parameterized Constructor)
 * Description: Initializes an expense object with given description and amount.
 * Parameters: const std::string& desc, double amt
 * Return: None
 *******************************************************************/
Expense::Expense(const std::string &desc, double amt) : description(desc), amount(amt) {}

/*******************************************************************
 * Function: setDescription
 * Description: Sets the expense's description.
 * Parameters: const std::string& desc - The description to set.
 * Return: None
 *******************************************************************/
void Expense::setDescription(const std::string &desc)
{
    description = desc;
}

/*******************************************************************
 * Function: getDescription
 * Description: Returns the expense's description.
 * Parameters: None
 * Return: std::string - The expense's description.
 *******************************************************************/
std::string Expense::getDescription() const
{
    return description;
}

/*******************************************************************
 * Function: setAmount
 * Description: Sets the expense's amount.
 * Parameters: double amt - The amount to set.
 * Return: None
 *******************************************************************/
void Expense::setAmount(double amt)
{
    amount = amt;
}

/*******************************************************************
 * Function: getAmount
 * Description: Returns the expense's amount.
 * Parameters: None
 * Return: double - The expense's amount.
 *******************************************************************/
double Expense::getAmount() const
{
    return amount;
}

/*******************************************************************
 * Function: containsDescription
 * Description: Checks if the expense's description contains a specified substring.
 * Parameters: const std::string& searchString - The substring to search for.
 * Return: bool - True if the description contains the substring, false otherwise.
 *******************************************************************/
bool Expense::containsDescription(const std::string &searchString) const
{
    std::string lowerDescription = description;
    std::string lowerSearchString = searchString;

    std::transform(lowerDescription.begin(), lowerDescription.end(), lowerDescription.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    std::transform(lowerSearchString.begin(), lowerSearchString.end(), lowerSearchString.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });

    return lowerDescription.find(lowerSearchString) != std::string::npos;
}
