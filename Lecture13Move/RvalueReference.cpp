#include<iostream>
#include<string>
using namespace std;

void print(int &&v)
{
    v+=1;
    cout<<v<<endl;
}

int main()
{
    int a1 = 1;
    int a2 = 2;
    auto&& a3 = a1 + a2; // 3
    // RvalueReference, expand the life time of "a1 + a2"

    const auto& a4 = a1 + 3;
    // You can bind a const value reference to an R-value
    // Meaning: can modify temporary expression, see line 5 and line 22

    a3 += 1; //4
    cout<<a3<<endl;

    print(1+3); // 5
}