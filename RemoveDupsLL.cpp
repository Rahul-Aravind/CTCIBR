#include<iostream>
#include<cstdio>
#include<map>

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

node* appendLLNode(node* head, int data)
{
    node* temp = addNode(data);
    node* p = head;

    while(p->next != NULL)
        p = p->next;

    p->next = temp;

    return head;
}

void printLL(node* head)
{
    node* p = head;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void removeDups(node* head)
{
    if(!head && !(head->next))return;

    node* p = head;
    map<int,bool>m;
    m.clear();

    node* prev=p;
    m[prev->data]=true;
    p=p->next;

    while(p)
    {

        if(m[p->data]==true)
        {
            prev->next = p->next;
            delete p;
            p = prev->next;
        }
        else
        {
            m[p->data]=true;
            prev = p;
            p = p->next;
        }
    }


}

int main()
{
    node* head = addNode(1);
    head = appendLLNode(head, 1);
    head = appendLLNode(head, 1);
    head = appendLLNode(head, 2);
    head = appendLLNode(head, 4);
    head = appendLLNode(head, 2);

    printLL(head);
    removeDups(head);
    printLL(head);

    return 0;

}
