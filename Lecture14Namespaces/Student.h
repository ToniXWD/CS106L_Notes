#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    Student();
    Student(std::string name, int age);
    void printStudent();
private:
    std::string m_Name;
    int m_Age;
};

