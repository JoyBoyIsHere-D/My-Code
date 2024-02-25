#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertBegin(Node *head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " " << endl;
        curr = curr->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *deletetail(Node *head){
    if (head==NULL)
        return NULL;
    Node *curr=head;
    if (head->next==NULL)
        {
            delete head;
            return NULL;
        }
    while (curr->next->next != NULL){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
    return head;
}

int main()
{
    Node *head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertBegin(head, 40);
    head = insertBegin(head, 50);
    
    printlist(head);
    cout << endl;
    head = deleteHead(head);
    printlist(head);
    return 0;
}