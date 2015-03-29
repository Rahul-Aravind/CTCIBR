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

void removeDups(node* &head)
{
    if(!head || !(head->next))return;

    for(node* p1 = head; p1; p1=p1->next)
    {
        node* prev = p1;
        for(node* p2=p1->next;p2;)
        {
            if(p1->data == p2->data)
            {
                prev->next = p2->next;
                delete p2;
                p2 = prev->next;
            }
            else
            {
                prev=p2;
                p2=p2->next;
            }
        }
    }
}

int main()
{
    node* head = addNode(1);
    head->next = addNode(2);
    head->next->next = addNode(1);
    head->next->next->next = addNode(1);
    head->next->next->next->next = addNode(2);

    printLL(head);
    removeDups(head);
    printLL(head);

    return 0;
}
