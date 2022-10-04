#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename T>
void showVector(const vector<T>& v)
{
    for(auto temp : v)
    {
        cout<<temp<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v1{1,3,5};
    showVector(v1);
    vector<int> v2{2,4,6};
    v2 = v1;
    v2[1] = 10;
    showVector(v1);
    showVector(v2);
}