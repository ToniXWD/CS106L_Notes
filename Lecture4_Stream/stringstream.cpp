#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    // istringstream
    string input = "a bcd ef\nghi\njk";
    istringstream i(input); // 必须包含line2的头文件sstream
    string a;
    string b;
    string c;
    string d;
    string e;
    i>>a>>b>>c>>d>>e;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;

    // flush
    int temp;
    // while (true)
    // {
    //     cin>>temp;
    //     if(cin.fail()) // cin.fail()可以写成 !cin
    //     {
    //         cout<<"Type must be int!"<<endl;
    //         break;
    //     }
    // }

    // 第20~28行可以简写成如下形式
    while (cin>>temp)
    {
        cout<<temp+1<<endl;
    }
}