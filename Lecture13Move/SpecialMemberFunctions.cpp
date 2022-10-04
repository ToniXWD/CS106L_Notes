#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
    Student()
    {
        cout<<"default constructor"<<endl;
    }
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
        cout<<"fill constructor"<<endl;
    }
    Student(const Student& s)
    {
        this->name = s.name;
        this->age = s.age;
        cout<<"copy constructor"<<endl;
    }
    ~Student()
    {
        cout<<"default destructor"<<endl;
    }
    Student& operator=(const Student& t)
    {
        cout<<"operator="<<endl;
        this->name = t.name;
        this->age = t.age;
        return *this;
    }
    string name;
    int age;
};

Student createS(string name, int age)
{
    Student temp(name,age);
    cout<<"createS returns"<<endl;
    return temp;
}

void PrintPerson(Student s)
{
    // 实参传递到形参时调用 copy constructor
    cout<<"Name:"<<s.name<<" Age:"<<s.age<<endl;
}

int main()
{
    Student s1 = createS("toni",18);
    cout<<"After Student s1 = createS('toni',18)"<<endl;
    // fill constructor
    // createS returns
    // default destructor

    // Student s2;
    // s2 = createS("tom",19);
    // // = 右侧的临时对象会在operator=后马上被析构
    // cout<<"after s2 = createS('tom',19);"<<endl; // 意味着函数返回时先调用=重载，再调用析构函数
    // // default constructor
    // // fill constructor
    // // createS returns
    // // operator=
    // // default destructor
    // // after s2 = createS('tom',19);
    // // PrintPerson(s2);

    // PrintPerson(Student("sam",20));
    // cout<<"After PrintPerson"<<endl;
    // // fill constructor
    // // Name:sam Age:20
    // // default destructor
    // // After PrintPerson
}