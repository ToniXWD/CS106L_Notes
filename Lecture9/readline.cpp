#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    ifstream file("example.txt");
    string temp;
    vector<string> readV;
    while (getline(file, temp))
    {
        readV.push_back(temp);
    }
    for(vector<string>::iterator it = readV.begin();it!=readV.end();it++)
    {
        cout<<*it<<endl;
    }
}