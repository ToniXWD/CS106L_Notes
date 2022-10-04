#include<iostream>
using namespace std;

int main()
{
    int a = 5;
    // static int a = 5;  不能捕获静态变量
    // []表示捕获变量，可以捕获引用
    /*
    [] :表示不捕获任何变量
    [=]：表示按值捕获变量
    [&]：表示按引用捕获变量
    [this]：值传递捕 获当前的this
    */

//    ->指定返回值类型，由于先指定了auto，可以省略
// lambda内部是一个单独的作用域

    auto lessthan2 = [a=3] (int i)->bool{ // 按值捕获时可以指定默认值
        cout<<"Capture:"<<a<<endl;
        return i<2;};
    cout<<lessthan2(1)<<endl;
}