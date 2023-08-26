#include <iostream>
#include <unordered_map>

using namespace std;

struct Node 
{ 
    int data; 
    Node *next,*random; 
    Node(int x) 
    { 
        data = x; 
        next = random = NULL; 
    } 
}; 

void print(Node *start) 
{ 
    Node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = "<< ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
}

Node* clone(Node* head)
{
    //Takes Extra space O(n);
    // unordered_map<Node*, Node*> mp;

    // for(Node* curr = head; curr != NULL; curr = curr -> next)
    //     mp[curr] = new Node(curr -> data);
    
    // for(Node* curr = head; curr != NULL; curr = curr -> next)
    // {
    //     mp[curr] -> next = mp[curr -> next];
    //     mp[curr] -> random =  mp[curr -> random];
    // }

    // Node* head2 = mp[head];

    // return head;

    Node* curr = head;
        
        if(!head)
            return NULL;
        
        while(curr != NULL)
        {
            Node* copy = new Node(curr -> data);
            copy -> next = curr -> next;
            curr -> next = copy;
            curr = copy -> next;
        }
        
        curr = head;
        
        for(Node* curr = head; curr != NULL; curr = curr -> next -> next)
            if (curr->random != NULL)
                curr->next->random = curr->random->next;
             
        curr = head;   
        Node* h2 = head -> next;
        
        for(Node* curr = head; curr != NULL; curr = curr -> next)
        {
            Node* copy = curr -> next;
            curr -> next = copy -> next;
            
            if(copy -> next != NULL)
                copy -> next = copy -> next -> next;
        }
        
        return h2;
}

int main() 
{ 
	Node* head = new Node(10); 
    head->next = new Node(5); 
    head->next->next = new Node(20); 
    head->next->next->next = new Node(15); 
    head->next->next->next->next = new Node(20); 
    
    head->random = head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;

    cout << "Original list : \n"; 
    print(head); 
    
    cout << "\nCloned list : \n"; 
    Node *cloned_list = clone(head); 
    print(cloned_list); 
  
    return 0; 
} 
