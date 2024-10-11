#include <bits/stdc++.h>
using namespace std;
struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};
void printLevel(Node *root){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false){
        Node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }

}

void printLevel2(Node *root){
    if (root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node *curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<'\n';
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
void printLevel3(Node *root){
    if (root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for (int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        cout<<'\n';
    }
}
int main(){
    Node *root=new Node(3);
	root->left=new Node(9);
	root->right=new Node(20);
	// root->left->left=new Node(40);
	// root->left->right=new Node(50);
	root->right->left=new Node(15);
	root->right->right=new Node(7);
	
	printLevel3(root);
    return 0;
}
