#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
    int data;
    node* next;
}*head;

node* addNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void printLL(node* head)
{
    node* p=head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

bool checkPalindrome(node* &a, node* b)
{
    if(!a || !b)return true;

    bool chk = checkPalindrome(a, b->next);
    if(!chk) return false;

    bool chk1 = a->data == b->data;
    a = a->next;

    return chk1;
}

int main()
{
    head = addNode(1);
    head->next = addNode(1);
    head->next->next = addNode(2);
    head->next->next->next = addNode(3);
    head->next->next->next->next = addNode(2);

    printLL(head);
    if(checkPalindrome(head, head))
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not a palindrome"<<endl;

    return 0;
}
