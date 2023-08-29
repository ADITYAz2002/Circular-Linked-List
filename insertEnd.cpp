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

Node* insertAtEnd(Node* head, int x)
{
    Node* new_node = new Node(x);

    if(head == NULL)
    {
        new_node -> next = new_node;
        return new_node;
    }
    
    else
    {
        new_node -> next = head ->next;     //adding new element after had;
        head -> next = new_node;

        int t = head -> data;
        head -> data = new_node -> data;
        new_node -> data = t;

        return new_node;
    }
}

void printlist(Node *head)
{
    if(head==NULL)
        return;

    Node *p=head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

int main()
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);

	head->next->next->next=head;

	head=insertAtEnd(head,15);
	printlist(head);
	return 0;
} 