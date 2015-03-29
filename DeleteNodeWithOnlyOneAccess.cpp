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

void deleteNode(node* n)
{
    if(!n && !(n->next)) return;

    n->data = n->next->data;
    n->next = n->next->next;
}

int main()
{
    head = addNode(1);
    head->next = addNode(2);
    head->next->next = addNode(3);
    head->next->next->next = addNode(1);
    head->next->next->next->next = addNode(2);

    printLL(head);
    node* n = head->next->next->next;
    deleteNode(n);
    printLL(head);

    return 0;
}
