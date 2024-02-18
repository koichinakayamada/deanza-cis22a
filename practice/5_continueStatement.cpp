#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    // loop from 1 to 10
    while (i < 10) {
        i++;
        // If i is equals to 5, continue to next iteration without printing
        if (i == 5){
            cout << " skip ";
            continue;
        }
        
        // Otherwise print the value of i
        cout << i << " ";
        cout << "test>";
    }

    return 0;
}