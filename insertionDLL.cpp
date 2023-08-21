#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next, * prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* append(Node **head, int data)
{
    Node* last = (*head) -> prev;

    Node* curr = new Node(data);

    curr -> next = *head;
    curr -> prev = last;

    last -> next = (*head) -> prev = curr;

    *head = curr;

    return *head;
}