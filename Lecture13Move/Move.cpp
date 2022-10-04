#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// Move constructor: create new from existing r-value
// Move assignment: overide existing from existing r-value

struct President
{
    string name;
    string country;
    int year;
    President(string p_name, string p_country, int p_year)
        : name(move(p_name)), country(move(p_country)), year(p_year)
    {
        cout<<"I am being constructed"<<endl;
    }
    President(const President& other)
        : name(move(other.name)), country(move(other.country)), year(other.year)
    {
        cout<<"I am being copied"<<endl;
    }
    // move
    President(President&& other)
        : name(move(other.name)), country(move(other.country)), year(other.year)
    {
        cout<<"I am being moved"<<endl;
    }
    President& operator=(const President& other) = default;
};

class myArrar
{
public:
    myArrar(int len)
    {
        this->length = len;
        this->array = new int[len];
    }
    myArrar(myArrar&& other)
    {
        // constructed from move constructor
        cout<<"constructed from move constructor"<<endl;
        this->array = other.array;
        this->length = other.length;
        other.array = nullptr; // important
    }
    myArrar& operator=(myArrar&& other)
    // r-value reference binds to an r-value, but r-value reference itself is a l-value
    {
        if(this->array != nullptr) delete[] this->array;
        // constructed from move= constructor
        cout<<"constructed from move= constructor"<<endl;
        // move turns the l-value to r-value
        this->array = move(other.array);
        this->length = move(other.length);
        other.array = nullptr; // important
        return *this;
    }
    myArrar operator+(const myArrar& arr)
    {
        cout<<"operator+"<<endl;
        int newlen = min(this->length, arr.length);
        myArrar newarr(newlen);
        for(int i=0; i<newlen; i++)
        {
            newarr.array[i] = this->array[i] + arr.array[i];
        }
        return newarr;
    }
    ~myArrar()
    {
        cout<<"destructor"<<endl;
        if(this->array != nullptr) delete[] this->array;
    }
    int *array = nullptr;
    int length = 0;
};

int main()
{
    // vector<President> elections;
    // cout<<"emplace_back"<<endl;
    // // Directly pass the parameters into the vector and create the vector inside with out creating twice
    // elections.emplace_back("Nelson Mandela", "South Africa", 1994);
    // elections.emplace_back(President("Jack Kenned", "USA", 1960));
    // for(vector<President>::iterator it = elections.begin(); it != elections.end(); it ++)
    // {
    //     cout<<"Name:"<<it->name<<" Country:"<<it->country<<" Year:"<<it->year<<endl;
    // }

    myArrar arr1(3);
    arr1.array[0] = 10;
    arr1.array[1] = 20;
    arr1.array[2] = 30;

    myArrar arr2(2);
    cout<<"before arr2 = arr1+arr1;"<<endl;
    arr2 = arr1+arr1;
    cout<<"after arr2 = arr1+arr1;"<<endl;
    cout<<arr2.array[0]<<" "<<arr2.array[1]<<" "<<arr2.array[2]<<endl;
}