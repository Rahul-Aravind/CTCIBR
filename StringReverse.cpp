#include<iostream>
#include<cstdio>

using namespace std;

void reverse(char* str)
{
    int start = 0;
    int end = 0;
    while(*(str+end))
        end++;
    --end;

    while(start < end)
    {
        char tmp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = tmp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "ab";
    cout<<str<<endl;
    reverse(str);
    cout<<"REVERSED STRING:"<<str<<endl;
}
