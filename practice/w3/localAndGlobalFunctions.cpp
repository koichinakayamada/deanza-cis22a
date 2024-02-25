#include <iostream>

// グローバル変数の定義: プログラムのどこからでもアクセス可能
int globalVar = 10;

// 関数の定義: ローカル変数を使用
void demoFunction()
{
    // ローカル変数の定義: この関数内でのみアクセス可能
    int localVar = 5;
    std::cout << "Local variable inside demoFunction: " << localVar << std::endl;

    // この関数内でもグローバル変数にアクセス可能
    std::cout << "Global variable accessed inside demoFunction: " << globalVar << std::endl;
}

int main()
{
    std::cout << "Global variable in main: " << globalVar << std::endl;

    // ローカル変数をmain関数内で定義
    int localVarInMain = 20;
    std::cout << "Local variable in main: " << localVarInMain << std::endl;

    // demoFunctionを呼び出し、ローカル変数とグローバル変数の挙動を確認
    demoFunction();

    // エラー: demoFunction内のローカル変数にはアクセス不可能
    // std::cout << localVar << std::endl; // コメントアウトを解除するとコンパイルエラーになる

    return 0;
}
