#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}



Node *reverseDoubly(Node *head){
    if (head==NULL||head->next==NULL)
        return head;
    Node *curr=head;
    Node *temp=NULL;
    while (curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;

        curr=curr->prev;//as prev and next are swapped, so we do this to increament the curr
    }
    return temp->prev;//to return the new head
}
int main()
{
    Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->prev=head;
	temp1->next=temp2;
	temp2->prev=temp1;
    printlist(head);
	head=reverseDoubly(head);
	printlist(head);
    return 0;
}