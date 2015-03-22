#include<iostream>
#include<cstring>
#include<map>

using namespace std;

int main() {
    string str = "rhytm";
    map<char, bool> m;
    bool chk = false;
    m.clear();

    for(int i=0; str[i]; i++) {
        if(m[str[i]] == true) {
            chk = true;
            break;
        }
        m[str[i]] = true;
    }

    if(chk == false)
        cout<<"The String has unique characters"<<endl;
    else
        cout<<"The String has no unique characters"<<endl;

    return 0;
}
