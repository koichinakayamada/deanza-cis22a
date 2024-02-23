#include <iostream>
using namespace std;

void printLine(char symbol);

int main()
{
   char myChar;

   myChar = '*';
   printLine(myChar);

   myChar = '#';
   printLine(myChar);

   myChar = '+';
   //printLine(myChar);
   printLine(myChar);

   printLine('^');

   return 0;
}

// passed by value
void printLine(char symbol)
{
  for (int i = 1; i <= 20; i++) {
    cout << symbol;
  }
  cout << "\n\n";
}
