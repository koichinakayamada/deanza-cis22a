#include <iostream>
using namespace std;

// 'add' 関数の定義。ここで 'a' と 'b' は仮引数です。
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // 'add' 関数の呼び出し。ここで '3' と '5' は実引数です。
    int result = add(3, 5);
    cout << "The result is " << result << endl;
    return 0;
}
