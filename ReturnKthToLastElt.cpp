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

node* returnKthFromlast(node* head, int k)
{
    if(!head || k<=0) return NULL;

    int count = 0;

    node* p = head;

    while(count < k)
    {
        if(p == NULL)
        {
            cout<<"K is greater than number of nodes in LL"<<endl;
            return NULL;
        }
        count++;
        p=p->next;
    }

    node* kNode = head;
    while(p)
    {
        p = p->next;
        kNode = kNode->next;
    }

    return kNode;
}

int main()
{
    node* head = addNode(1);
    head->next = addNode(2);
    head->next->next = addNode(3);
    head->next->next->next = addNode(1);
    head->next->next->next->next = addNode(2);

    printLL(head);
    node* n = returnKthFromlast(head, 6);

    if(n!=NULL)
        cout<<n->data<<endl;
    else
        cout<<"LL is empty or K is greater or lesser than the number of nodes in LL"<<endl;

    return 0;
}
