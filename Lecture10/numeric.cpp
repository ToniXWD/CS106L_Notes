#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

// 内积
template<typename T>
float dotProduct(const T& vec1, const T& vec2)
{
    return inner_product(vec1.begin(),vec1.end(),vec2.begin(),0);
    // 0表示做内积后再加上的初始值
}

// 向量长度
template<typename T>
float mag(const T& vec)
{
    // dotProduct在numeric中,sqrt在cmath中
    return sqrt(dotProduct(vec,vec));
}

// cosθ
template<typename T>
float cosVec(const T& vec1, const T& vec2)
{
    return dotProduct(vec1, vec2)/mag(vec1)/mag(vec2);
}

int main()
{
    vector<float> v1{1,0};
    vector<float> v2{1,1};
    cout<<cosVec(v1,v2)<<endl;
}