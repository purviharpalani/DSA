#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
	struct node *left;
	int data;
	struct node *right;
	
	node(int val){
	    data=val;
	    left = right = NULL;
	}
};

vector<int> iterPreorder(node* root){
    std::stack<node*> s;
    vector<int> res;
    if(root==NULL) return res;
    
    s.push(root);
    while(!s.empty()){
        node* n = s.top();
        s.pop();
        if(n->right!=NULL){s.push(n->right);}
        if(n->left!=NULL){s.push(n->left);}
        res.push_back(n->data);
        
    }
    return res;
}

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->right = new node(7);
    root->left->right = new node(4);
    root->left->right->left = new node(5);
    root->left->right->right = new node(6);
    
    vector<int> res=iterPreorder(root);
    for(int i:res)
    cout<<i;

    return 0;
}
