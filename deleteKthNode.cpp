#include <iostream>
using namespace std;

struct Node
{
    int data;

    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* delHead(Node* head)
{
    if(head == NULL)
        return NULL;
    
    if(head -> next == NULL)
    {
        delete head;
        return NULL;
    }

    head -> data = head -> next -> data;
    Node* temp = head -> next;

    head -> next = head -> next -> next;
    delete temp;

    return head;
}

Node* delKth(Node* head, int k)
{
    if(head == NULL)
        return head;
    
    if(k == 1)
        return delHead(head);

    Node *curr = head;

    for(int i = 0; i < k-2; i++)
        curr = curr -> next;
    
    Node* temp = curr -> next;
    curr -> next = curr -> next -> next;
    delete temp;

    return head;
}

void printlist(Node *head)
{
    if(head==NULL)return;

    Node *p=head;

    while(true)
    {
        cout<<p->data<<" ";
        p=p->next;

        if(p == head)
            break;
    }
}

int main()
{
    Node* head = new Node(5);
    head -> next = new Node(10);
    head -> next -> next = new Node(15);
    head -> next -> next -> next = new Node(20);

    head = delKth(head, 3);

    printlist(head);
}