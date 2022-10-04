#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"Student.h"

using std::endl;
using std::vector;
using std::cout;

namespace Lecture{
    int count(const vector<int>& v, int tar){
        int ctr = 0;
        for(auto i : v){
            if(i==tar){
                ++ctr;
            }
        }
        return ctr;
    }
}

int main()
{
    vector<int> v1{3,1,4,1,5,9};
    int count = 0;
    cout<<"algorithm count: "<<std::count(v1.begin(), v1.end(), 1)<<endl;
    cout<<"self namespace count: "<<Lecture::count(v1, 1)<<endl;
    Student s1("toni", 18);
    s1.printStudent();
}