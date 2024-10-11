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

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  
void preorder(Node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);    
    }
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);    
        cout<<root->key<<" ";
    }
}
vector<vector<int>> zigzagLevelOrder(Node* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        int it = 1;
        vector<int> res;
        res.push_back(root->key);
        result.push_back(res);
        res.clear();

        while (q.empty() == false) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                it++;
                if(it%2==0)
                    reverse(res.begin(),res.end());
                result.push_back(res);
                res.clear();
                q.push(NULL);
                continue;
            } 
            else {
                if (curr->left != NULL) {
                    q.push(curr->left);
                    res.push_back(curr->left->key);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                    res.push_back(curr->right->key);
                }
            }
            
            
        }
        return result;
    }
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);

    vector<vector<int>> result =zigzagLevelOrder(root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	
	// inorder(root);
}