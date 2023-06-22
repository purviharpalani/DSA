#include <iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* left;
    int data;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>> res;
    queue<Node*> q;
    if(root == NULL) return res;
    
    q.push(root);
    while(!q.empty()){
        vector<int> ans;
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            ans.push_back(node->data);
        }
        res.push_back(ans);
    }
    return res;
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(8);
    root->left->left->left = new Node(9);
    root->right = new Node(3);
    root->right->left=new Node(7);
    root->right->right=new Node(6);
    root->right->right->left=new Node(10);
    root->right->right->right=new Node(11);
    
    vector<vector<int>> ans = zigzagTraversal(root);
    int count = 0;
    for(vector<int> vect : ans){
        count++;
        if(count%2==0) reverse(vect.begin(),vect.end());
        for(int i : vect){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
