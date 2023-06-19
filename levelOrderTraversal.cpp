#include <iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>

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

vector<vector<int>> levelOrderTraversal(Node* root){
	map<int,map<int,multiset<int>>> nodes;
	queue<pair<Node*, pair<int,int>>> todo;
	todo.push({root,{0,0}});
	while(!todo.empty()){
		auto p = todo.front();
		todo.pop();
		Node* node = p.first;
		int x = p.second.first;
		int y = p.second.second;
		nodes[x][y].insert(node->data);
		if(node->left) todo.push({node->left,{x-1, y+1}});
		if(node->right) todo.push({node->right,{x+1, y+1}});
	}
	vector<vector<int>> res;
	for(auto p : nodes){
		vector<int> col;
		for(auto q : p.second){
			col.insert(col.end(), q.second.begin(), q.second.end());
		}
		res.push_back(col);
	}
	return res;
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(11);    
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->left=new Node(9);
    root->right->right=new Node(10);
    
    vector<vector<int>> levelOrder = levelOrderTraversal(root);
    for(vector<int> vect : levelOrder){
    	for(int x : vect){
    		cout<<x<<" ";
		}
		cout<<endl;
	}
    
    return 0;
    
}
