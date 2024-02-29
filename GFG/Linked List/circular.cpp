#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void printlist(Node *head){
    if(head==NULL)return;
    cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
        cout<<p->data<<" ";
}

Node *insertBegin(Node *head, int data){
    Node *temp=new Node (data);
    if (head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else {
        temp->next=head->next;
        head->next=temp;//swapping the pointers by inserting the temp at position 2

        int t=temp->data;//swapping the data so that the data in temp gets in head
        temp->data=head->data;
        head->data=t;

        return head;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(5);
	head->next->next=new Node(20);
	head->next->next->next=new Node(15);
	head->next->next->next->next=head;
	printlist(head);
	return 0;
} 