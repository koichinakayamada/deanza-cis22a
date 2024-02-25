#include <iostream>
using namespace std;

void print(int i){

    cout << i << endl;
}

void print(double i){

    cout << i << endl;
}

void print(char i){

    cout << i << endl;
    cout << "This is char." << endl;
}

int main(){
    print(10);
    print(10.5);
    print('A');
    return 0;
}