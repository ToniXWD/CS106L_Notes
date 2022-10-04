#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<iterator>
#include<set>


using std::cout;
using std::ifstream;
using std::string;
using std::endl;

string file2string(ifstream& file)
{
    string ret ="";
    string line;

// ? 不理解while(std::getline(file,line))
    while(file>>line)
    {
        // cout<<line;
        // transform
        std::transform(line.begin(),line.end(),line.begin(),tolower);
        ret += line + " ";
    }
    return ret;
}

int countOccurrences(const string& word, const string& text)
{
    string toFind = " " + word + " ";

    // search
    auto curr = text.begin();
    auto end = text.end();
    int count=0;

    while(curr != end)
    {
        auto found = std::search(curr, end, word.begin(), word.end());
        if(found == end) break; // 可以不用写在{}里
        ++count;
        // curr = found + 1;
        // found指向找到的文本的第一个字符
        cout<<*curr<<endl;
    }
    return count;
}

int main()
{
    ifstream file1("example.txt");
    string text = file2string(file1);
    cout<<countOccurrences("toni",text)<<endl;
}