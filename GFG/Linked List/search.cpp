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

int search(Node *head, int x)
{
    int i;
    Node *curr = head;
    for (i = 1; curr != NULL; i++)
    {
        if (curr->data == x)
        {
            return i;
        }
        curr = curr->next;
    }
    return -1;
}
int main()
{
    Node *head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 30);
    head = insertBegin(head, 60);
    head = insertBegin(head, 45);
    head = insertBegin(head, 26);
    head = insertBegin(head, 43);
    printlist(head);
    cout<<endl;
    cout<<search(head,45);
    return 0;
}