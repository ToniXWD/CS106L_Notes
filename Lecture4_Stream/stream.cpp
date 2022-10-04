#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    std::ifstream fromfile("./t.txt",std::ifstream::out);
    // ifstream fromfile;
    // ?
    char a = 97;
    fromfile.get(a);
}