#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool isPermutation(string str1, string str2)
{
    if(str1.size() != str2.size())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if(str1==str2)
        return true;
    else
        return false;
}

int main()
{
    string a = "abcd";
    string b = "bcad";

    if(isPermutation(a,b))
        cout<<"Permutation"<<endl;
    else
        cout<<"Not a permutation"<<endl;

    return 0;
}
