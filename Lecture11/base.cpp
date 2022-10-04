#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 必须重载为成员函数的：[],(),->,=
// 必须重载为非成员函数的：<<
// 一元运算符建议重载为成员函数
// 如果二元运算符平等处理二个操作数，使用非成员函数
// 如果二元运算符不平等处理二个操作数，使用成员函数

// 1 重载+=
vector<string>& operator+=(vector<string>&v, const string& val)
{
    v.push_back(val);
    return v;
}

// 2 重载+
vector<string> operator+(const vector<string>&v1, const vector<string>&v2)
{
    vector<string> v(v1);
    for(auto temp : v2) v.push_back(temp);
    return v;
}

ostream& operator<<(ostream& os, const vector<string>& v)
{
    for(const auto& temp : v) os<<temp<<" ";
    os<<endl;
    return os;
}



int main()
{
    vector<string> v{"Hello", "World"};

    v += "!";

    vector<string> v2{"I","am","xwd"};

    vector<string> v3 = v + v2;

    cout<<v3;
}