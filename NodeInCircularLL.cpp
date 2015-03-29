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

node* returnLoopNode(node* head)
{
    if(!(head) || !(head->next) || (head->next == head)) return head;

    node* p1 = head;
    node* p2 = head;

    while(p1->next && p2->next && p2->next->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;

        if(p1 == p2) break;
    }

    if(p1 != p2)return NULL; // no loop

    p1=head;

    while(p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }

    return p1;

}

int main()
{
    head = addNode(1);
    head->next = addNode(2);
    head->next->next = addNode(3);
    head->next->next->next = addNode(4);
    head->next->next->next->next = addNode(5);
    head->next->next->next->next->next = head->next->next->next;

    node* loopNode = returnLoopNode(head);
    if(loopNode == NULL)
        cout<<"No Loop in LL"<<endl;
    else
        cout<<loopNode->data<<endl;

    return 0;
}
