#include <iostream>
using namespace std;

// Here is a global variable
int twoNames = 5;

int main()
{
    // local variable with same name
    int twoNames =2;
    cout << twoNames << endl; // local variable will be printed
    cout << ::twoNames << endl; // global variable will be printed
}
