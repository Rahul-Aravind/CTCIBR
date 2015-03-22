#include<iostream>
#include<cstdio>

using namespace std;

void replaceChars(char str[], int len)
{
    int i = 0;
    int spaces = 0;
    for(int i=0; i<len; i++)
        if(str[i] == ' ')spaces++;

    int adjustLen = len + spaces*2;
    str[adjustLen]='\0';
    adjustLen--;
    for(int i=len-1; i>=0;i--)
    {
        if(str[i]==' ')
        {
            str[adjustLen] = '0';
            str[adjustLen-1]= '2';
            str[adjustLen-2]= '%';
            adjustLen-=3;
        }
        else
        {
            str[adjustLen]=str[i];
            adjustLen-=1;
        }
    }

    cout<<str<<endl;

}

int main()
{
    char str[] = "Mr John a Smith    ";
    int len = 15;
    replaceChars(str, len);

    return 0;
}
