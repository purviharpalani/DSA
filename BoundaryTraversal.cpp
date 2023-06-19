#include <iostream>
#include<vector>

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

bool isLeaf(Node* node){
    if((node->left == NULL) && (node->right == NULL)) return true;
    else return false;
}


void leftBoundary(Node* root, vector<int> &res){
    Node* curr = root->left;
    while(curr){
    if(!isLeaf(curr)) res.push_back(curr->data);
    if(curr->left) curr=curr->left;
    else curr = curr->right;}
}

void addLeaf(Node* root, vector<int> &res){
    Node* curr = root;
    if(isLeaf(curr)) {
        res.push_back(curr->data);
        return;
    }
    if(curr->left) addLeaf(curr->left, res);
    if(curr->right) addLeaf(curr->right, res);
    
}

void rightBoundary(Node* root, vector<int> &res){
    vector<int> temp;
    Node* curr = root->right;
    while(curr){
    if(!isLeaf(curr)) temp.push_back(curr->data);
    if(curr->right) curr=curr->right;
    else curr = curr->left;}
    
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

vector<int> printBoundary(Node* root){
    vector<int> res;
    if(root==NULL) return res;
    res.push_back(root->data);
    leftBoundary(root, res);
    addLeaf(root, res);
    rightBoundary(root, res);
    return res;
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->left->left=new Node(10);
    root->right->right->left->right =new Node(11);
    
    vector<int> boundaryVector = printBoundary(root);
    for(int i:boundaryVector)
    cout<<i<<" ";
    
    return 0;
    
}
