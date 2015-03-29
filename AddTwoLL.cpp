#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
    int data;
    node* next;
};

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

int count(node* head)
{
    int count = 0;
    node* p = head;

    while(p)
    {
        count++;
        p = p->next;
    }

    return count;
}

void pushNode(node* &total, int data)
{
    node* temp = addNode(data);
    node* p = total;
    if(!p) total = temp;
    else
    {
        while(p->next)p = p->next;
        p->next = temp;
    }
}

node* add(node* a, node* b)
{
    int carry = 0;
    node* total = NULL;

    while(b)
    {
        int sum = a->data + b->data + carry;
        carry = sum/10;
        int val = sum%10;
        pushNode(total, val);
        a = a->next;
        b = b->next;
    }

    while(a)
    {
        int sum = a->data + carry;
        carry = sum/10;
        int val = sum%10;
        pushNode(total, val);
        a = a->next;
    }

    if(carry)
        pushNode(total, carry);

    return total;
}

int main()
{
    node* num1 = addNode(7);
    num1->next = addNode(9);
   // num1->next->next = addNode(6);
   // num1->next->next->next = addNode(9);
   
    node* num2 = addNode(5);
    num2->next = addNode(9);
    num2->next->next = addNode(9);

    printLL(num1);
    printLL(num2);

    int count1 = count(num1);
    int count2 = count(num2);

    if(count1 > count2)
        printLL(add(num1,num2));
    else
        printLL(add(num2,num1));

    return 0;
}
