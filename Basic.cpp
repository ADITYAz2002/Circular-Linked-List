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

void printList(Node* head)
{
    Node* curr = head;

    if(head != NULL)
    {
        do
        {
        cout<<curr -> data<<" ";
        curr = curr -> next;
        } while(curr != head);
    }
}

int main()
{
    Node *head = new Node(10);
    head -> next = new Node(5);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(15);

    printList(head);
    
    return 0;
}