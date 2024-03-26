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
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "expense.h"

/*******************************************************************
 * Function: showMenu
 * Description: Displays the main menu options to the user.
 * Parameters: None
 * Return: None
 *******************************************************************/
void showMenu()
{
    std::cout << "\nExpense Tracking Menu:\n"
              << "1. Show all\n"
              << "2. Spend\n"
              << "3. Search expenses containing this string\n"
              << "4. Search expenses with greater than or equal to this amount\n"
              << "5. Exit\n"
              << "Enter your option: ";
}

/*******************************************************************
 * Function: addExpense
 * Description: Adds a new expense entry to the vector of expenses.
 * Parameters: std::vector<Expense>& expenses - the vector holding all expenses
 * Return: None
 *******************************************************************/
void addExpense(std::vector<Expense> &expenses)
{
    std::string description;
    double amount;

    std::cout << "Please enter the description for the expense: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, description);

    std::cout << "Please enter the amount: ";
    std::cin >> amount;

    if (amount > 0 && !description.empty())
    {
        expenses.emplace_back(description, amount);
        std::cout << "Expense added successfully.\n";
    }
    else
    {
        std::cout << "Invalid input. Amount must be positive and description cannot be empty.\n";
    }
}

/*******************************************************************
 * Function: showAllExpenses
 * Description: Displays all expenses recorded.
 * Parameters: const std::vector<Expense>& expenses - the vector holding all expenses
 * Return: None
 *******************************************************************/
void showAllExpenses(const std::vector<Expense> &expenses)
{
    if (expenses.empty())
    {
        std::cout << "There are no expenses to display.\n";
    }
    else
    {
        for (const auto &expense : expenses)
        {
            std::cout << "Amount: " << expense.getAmount()
                      << ", Description: " << expense.getDescription() << std::endl;
        }
    }
}

/*******************************************************************
 * Function: searchExpensesByDescription
 * Description: Searches for expenses by a given description.
 * Parameters: const std::vector<Expense>& expenses - the vector holding all expenses
 * Return: None
 *******************************************************************/
void searchExpensesByDescription(const std::vector<Expense> &expenses)
{
    std::string searchStr;
    std::cout << "Enter description to search for: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, searchStr);

    bool found = false;
    for (const auto &expense : expenses)
    {
        if (expense.containsDescription(searchStr))
        {
            std::cout << "Amount: " << expense.getAmount()
                      << ", Description: " << expense.getDescription() << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No expenses match your search criteria.\n";
    }
}

/*******************************************************************
 * Function: searchExpensesByAmount
 * Description: Searches for expenses greater than or equal to a given amount.
 * Parameters: const std::vector<Expense>& expenses - the vector holding all expenses
 * Return: None
 *******************************************************************/
void searchExpensesByAmount(const std::vector<Expense> &expenses)
{
    double amount;
    std::cout << "Enter minimum amount to search for: ";
    std::cin >> amount;

    bool found = false;
    for (const auto &expense : expenses)
    {
        if (expense.getAmount() >= amount)
        {
            std::cout << "Amount: " << expense.getAmount()
                      << ", Description: " << expense.getDescription() << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No expenses meet or exceed the specified amount.\n";
    }
}

/*******************************************************************
 * Function: loadExpensesFromFile
 * Description: Loads expenses from a file into the vector.
 * Parameters: std::vector<Expense>& expenses - the vector to load expenses into
 * Return: None
 *******************************************************************/
void loadExpensesFromFile(std::vector<Expense> &expenses)
{
    std::ifstream inFile("expenses.txt");
    if (!inFile)
    {
        std::cout << "No existing expenses file found, starting new.\n";
        return;
    }

    std::string description;
    double amount;
    while (inFile >> amount && std::getline(inFile >> std::ws, description))
    {
        expenses.emplace_back(description, amount);
    }
}

/*******************************************************************
 * Function: saveExpensesToFile
 * Description: Saves all expenses from the vector into a file.
 * Parameters: const std::vector<Expense>& expenses - the vector of expenses to save
 * Return: None
 *******************************************************************/
void saveExpensesToFile(const std::vector<Expense> &expenses)
{
    std::ofstream outFile("expenses.txt");
    for (const auto &expense : expenses)
    {
        outFile << expense.getAmount() << "\n"
                << expense.getDescription() << "\n";
    }
}

int main()
{
    std::vector<Expense> expenses;
    loadExpensesFromFile(expenses);
    int choice;

    do
    {
        showMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            showAllExpenses(expenses);
            break;
        case 2:
            addExpense(expenses);
            break;
        case 3:
            searchExpensesByDescription(expenses);
            break;
        case 4:
            searchExpensesByAmount(expenses);
            break;
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid option, please try again.\n";
        }
    } while (choice != 5);

    saveExpensesToFile(expenses);
    return 0;
}
