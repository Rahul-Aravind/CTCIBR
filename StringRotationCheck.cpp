#include<iostream>
#include<cstdio>

using namespace std;

bool isSubstring(string pattern, string target)
{
    for(int i=0; i<= target.size() - pattern.size(); i++)
    {
        int j=0;
        while(j < pattern.size() && pattern[j] == target[i+j])j++;

        if(j == pattern.size())
            return true;
    }

    return false;
}

int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewaa";

    if(s1.size() == s2.size() && s1.size()>0 && isSubstring(s2, s1.append(s1)))
        cout<<"Rotation"<<endl;
    else
        cout<<"Not a rotation"<<endl;

    return 0;
}
