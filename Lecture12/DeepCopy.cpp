#include<iostream>
#include<string>
using namespace std;

class myArray
{
public:
    myArray(){}
    myArray(int length)
    {
        this->m_Length = length;
        this->m_Array = new int[length];
        for(int i = 0; i<length; i++) this->m_Array[i] = i +1;
    }

    ~myArray()
    {
        if(this->m_Array != NULL) delete[] m_Array;
        this->m_Array = NULL;
    }

    int m_Length;
    int* m_Array;
};

class newArray
{
public:
    newArray(){}

    newArray(int length)
    {
        this->m_Length = length;
        this->m_Array = new int[length];
        for(int i = 0; i<length; i++) this->m_Array[i] = i +1;
    }

    newArray(const newArray& t)
    {
        this->m_Length = t.m_Length;
        this->m_Array = new int(t.m_Length);
        for (size_t i = 0; i < t.m_Length; i++)
        {
            this->m_Array[i] = t.m_Array[i];
        }
    }

    ~newArray()
    {
        if(this->m_Array != NULL) delete[] m_Array;
        this->m_Array = NULL;
    }

    newArray& operator=(const newArray& t)
    {

        if(this->m_Array != NULL) delete[] m_Array;
        this->m_Array = NULL;
        this->m_Length = t.m_Length;
        this->m_Array = new int(t.m_Length);
        for (size_t i = 0; i < t.m_Length; i++)
        {
            this->m_Array[i] = t.m_Array[i];
        }
        return *this;
    }

    int m_Length=0;
    int* m_Array=NULL;
};

int main()
{
    myArray a1(3);
    myArray a2(a1);
    myArray a3;
    a3 = a1;
    a1.m_Array[1] = 10;
    cout<<"a2.m_Array[1]="<<a2.m_Array[1]<<endl;
    cout<<"a3.m_Array[1]="<<a3.m_Array[1]<<endl;
    // a2.m_Array[1] and a3.m_Array[1] change with a1
    // 且在析构时会重复析构
    newArray A1(3);
    newArray A2(A1);
    newArray A3;
    A3 = A1; // = 重载
    A1.m_Array[1] = 10;
    cout<<"A2.m_Array[1]="<<A2.m_Array[1]<<endl;
    cout<<"A3.m_Array[1]="<<A3.m_Array[1]<<endl;
    // A2.m_Array[1] does not change with A1
}