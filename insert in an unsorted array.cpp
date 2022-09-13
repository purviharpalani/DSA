// insert in an unsorted array
// time complexity - O(1)
// auxiliary space - O(1)
#include<iostream>
using namespace std;

int insert(int arr[],int n,int capacity,int key){
	if(n>=capacity){
		return n;
	}
	else{
		arr[n]=key;
		return n+1;
	}
}

int main(){
	int arr[20]={12,5,8,19,10,3};
	int capacity=sizeof(arr)/sizeof(arr[0]);
	int n=6;
	cout<<"Before insertion:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	int key=7;
	n=insert(arr,n,capacity,key);
	cout<<"\nAfter insertion:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

