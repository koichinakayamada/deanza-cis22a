#include <iostream>
using namespace std;

int square(int x);
int cube(int x);

int main(){

    int i, i3;
    cout << "Please enter a number: " << endl;
    cin >> i;
    cout << "Square of " << i << " is " << square(i) << endl;

    i3 = cube(i);
    cout << "Cube of " << i << " is " << i3 << endl;
    return 0;
}

int square(int x){
    return x*x;
}

int cube(int x){
    return x*x*x;
}
