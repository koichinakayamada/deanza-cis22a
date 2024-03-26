#include <iostream>
#include <array>
using namespace std;

int main(){
    // int const ARRAY_SIZE = 5;
    // int numbers[ARRAY_SIZE];
    /*
    numbers is the name of the array,
    and ARRAY_SIZE is just a size of array
    which was definded at on previous line
    */

    // For loop is often used in terms of Allay
    for (int count = 0; count < ARRAY_SIZE; count++)
    {
        numbers[count] = 99;
    }

    const int SIZE = 5;
    int scores[SIZE] = {}; // Initialize all to 0

    const int SECOND_SIZE = 5;
    int scores[] = {79, 21, 32, 53, 43};
    // これらを一行にまとめることは構造上不可能である

    // int myArray[10];
    // int myArray[5] = {1, 2, 3, 4, 5};
    // int myArray[] = {1, 2, 3, 4, 5};

    // myArray[] = 10;
    // cout << myArray[2];

    int myArray[5] = {1, 2, 3, 4, 5};
    // 宣言と初期化を同時に行うことができているので基本形として捉えていい

    // We can use not only the int but also any other like string for array
    string daysOfTheWeek[] = {"Monday", "Tuesday"};

    // Array assignment
    int newScores;
    for (i =0; i < ARRAY_SIZE; i++){
        newScores[i] = scores[i];
    }
}
