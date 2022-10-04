#include"Student.h"

Student::Student(){
    this->m_Name = "";
    this->m_Age = 0;
}

Student::Student(std::string name, int age){
    this->m_Name = name;
    this->m_Age = age;
}

void Student::printStudent()
{
    std::cout<<"Name: "<<this->m_Name<<" Age: "<<this->m_Age<<std::endl;
}