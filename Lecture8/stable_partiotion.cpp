#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student
{
public:
    Student(string name, string subject)
    {
        this->m_Name = name;
        this->m_Subject = subject;
    }
    // Student(const Student& temp)
    // {
    //     this->m_Name = temp.m_Name;
    //     this->m_Subject = temp.m_Subject;
    // }
    // Student& operator=(const Student& temp)
    // {
    //     return Student(temp);
    // }
    string m_Name;
    string m_Subject;
};

int main()
{
    // 一 stable_partition
    // example1
    vector<int> v{1,2,3,4,5,6,7,8,9};
    auto isOdd = [](auto element){
        return element%2==1;
    };
    stable_partition(v.begin(),v.end(),isOdd);
    for(vector<int>::iterator p = v.begin();p!=v.end();p++)
    {
        cout<<*p<<" ";
    }
    cout<<endl;
    // vector<int> v2;
    // v2.resize(v.size());
    // copy(v.begin(),v.end(),v2.begin());

    // example2
    vector<Student> s{
        Student("Tom","CS106L"),
        Student("Sam","CS61A"),
        Student("Clark","CS61B"),
        Student("Jim","CS106L"),
        Student("Jack","CS61C"),
        Student("Sally","CS106L"),
    };
    vector<Student> s2(s);
    // vector<Student> s2;
    // s2.resize(s.size());
    copy(s.begin(),s.end(),s2.begin());

    auto takeCS106L = [](const Student& s) {
        // substr可以从指定位置到结束位置（不包括结束位置）截取后返回复制的字符串
        return s.m_Subject.substr(0,6) == "CS106L";
    };
    
    stable_partition(s.begin(),s.end(),takeCS106L);

    cout<<"原顺序"<<endl;
    for(vector<Student>::iterator ps = s2.begin();ps!= s2.end();ps++)
    {
        cout<<"Name:"<<ps->m_Name<<" Subject:"<<ps->m_Subject<<endl;
    }

    cout<<endl;
    cout<<"stable_partition后的顺序"<<endl;
    for(vector<Student>::iterator ps = s.begin();ps!= s.end();ps++)
    {
        cout<<"Name:"<<ps->m_Name<<" Subject:"<<ps->m_Subject<<endl;
    }

    // 二 copy和copy_if
    // copy_if()
    auto takeCS61 = [](const Student& s) {
        // substr可以从指定位置到结束位置（不包括结束位置）截取后返回复制的字符串
        return s.m_Subject.substr(0,4) == "CS61";
    };
    vector<Student> s3;
    // back_inserter接受一个容器，返回一个可以插入的iterator，而可以不考虑目标容器的size
    copy_if(s2.begin(),s2.end(),back_inserter(s3), takeCS61);
    
    cout<<endl;
    cout<<"CS61系列筛选"<<endl;
    for(vector<Student>::iterator ps = s3.begin();ps!= s3.end();ps++)
    {
        cout<<"Name:"<<ps->m_Name<<" Subject:"<<ps->m_Subject<<endl;
    }
    // copy
    vector<Student> s4;
    copy(s3.begin(),s3.end(),back_inserter(s4));
    cout<<endl<<"copy算法copyCS61系列筛选后的结果"<<endl;
    for(vector<Student>::iterator ps = s4.begin();ps!= s4.end();ps++)
    {
        cout<<"Name:"<<ps->m_Name<<" Subject:"<<ps->m_Subject<<endl;
    }

    // 三 remove_if和erase
    vector<Student> s5(s2);
    // remove并非是删除，只是将目标放在容器后面，看做是垃圾,返回首个垃圾的iterator
    // 配合erase使用，erase删除两个iterator之间的对象
    s5.erase(remove_if(s5.begin(),s5.end(),takeCS106L),s5.end());
    cout<<endl<<"remove CS106L"<<endl;
    for(vector<Student>::iterator ps = s5.begin();ps!= s5.end();ps++)
    {
        cout<<"Name:"<<ps->m_Name<<" Subject:"<<ps->m_Subject<<endl;
    }
}