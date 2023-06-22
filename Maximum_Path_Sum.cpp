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

int calcSum(Node* root, int &maxi){
    if(root==NULL) return 0;
    int leftSum = max(0, calcSum(root->left, maxi));
    int rightSum = max(0, calcSum(root->right, maxi));
    maxi = max(maxi, root->data + leftSum +rightSum);
    return (root->data + max(leftSum, rightSum));
}

int maximumPathSum(Node* root){
    if(root==NULL) return 0;
    int maxi = 0;
    calcSum(root, maxi);
    return maxi;
}

int main()
{
    struct Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    int ans = maximumPathSum(root);
    cout<<ans;
    
    return 0;
    
}
