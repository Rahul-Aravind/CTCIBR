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

void partitionLL(node* &head, int x)
{
    if(!head || !(head->next))return;

    node* start = head;
    node* tail = head;

    node* p = head;
    while(p)
    {
        node* next = p->next;
        if(p->data < x)
        {
            p->next = start;
            start = p;
        }
        else
        {
           tail->next = p;
           tail = p;
        }
        p = next;
    }
    tail->next = NULL;
    head = start;

}

int main()
{
    head = addNode(1);
    head->next = addNode(3);
    head->next->next = addNode(4);
    head->next->next->next = addNode(2);
    head->next->next->next->next = addNode(1);

    printLL(head);
    partitionLL(head, 4);
    printLL(head);

    return 0;
}
