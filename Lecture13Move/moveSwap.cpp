#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename T>
void swap(T& a, T& b)
{
    cout<<"move"<<endl;
    T temp = move(a);
    a = move(b);
    b = move(temp);
}

int main()
{
    vector<string> v1(10, "Anna");
    vector<string> v2(20, "Tom");

    swap(v1, v2);

    for(auto i : v1) cout<<i<<" ";
    cout<<endl;
    for(auto i : v2) cout<<i<<" ";
    cout<<endl;
}