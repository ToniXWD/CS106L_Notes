#include<iostream>
#include<string>
using namespace std;

class myClass
{
    const int* const myClassMethod(const int* const & param) const;
    // const int* const & param: A const pointer a to constant int by reference
};