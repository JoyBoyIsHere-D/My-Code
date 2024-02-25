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

Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node *insertPos(Node *head, int data, int pos)
{
    Node *temp = new Node(data);
    Node *curr = head;
    int t = pos - 2;
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    while (t-- && curr != NULL)
    {
        curr = curr->next;
    }
    if (curr == NULL)
        return head;
    temp->next = curr->next;
    curr->next = temp;
    return head;
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

int main()
{
    // Node *head = new Node(10);
    // Node *temp1 = new Node(20);
    // Node *temp2 = new Node(30);
    // head->next = temp1;
    // temp1->next = temp2;
    Node *head = NULL;
    head = insertBegin(head, 10);
    head = insertEnd(head, 420);
    head = insertBegin(head, 20);
    head = insertEnd(head, 69);
    head = insertBegin(head, 30);
    
        printlist(head);
    // cout<< head->data<<"-->"<<temp1->data<<"-->"<<temp2->data;

    return 0;
}