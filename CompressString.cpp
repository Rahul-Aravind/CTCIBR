#include<iostream>
#include<cstdio>

using namespace std;

string compressedString(string str)
{
    if(str.size() < 2) return str;

    int count = 1;
    string compressedString = "";
    for(int i=1; i<= str.size();)
    {
        while(i < str.size() && str[i]==str[i-1])
        {
            count++;
            i++;
        }
        compressedString += str[i-1];
        if(count != 1)
            compressedString += '0' + count;
        count = 1; // reset
        i++;
    }

    if(compressedString.size() < str.size())
        return compressedString;
    else
        return str;
}

int main()
{
    string str = "aaab";
    cout<<compressedString(str)<<endl;

    return 0;
}
