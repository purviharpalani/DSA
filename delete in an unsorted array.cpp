//delete in an unsorted array
// time complexity - O(n)
// auxiliary space - O(1)
#include<iostream>
using namespace std;
int search(int arr[],int n,int key){
	int pos=-1;
	for(int i=0;i<n;i++){
		if(arr[i]==key)
			pos=i;
	}
	return pos;
}
int delete_key(int arr[],int n,int key){
	int pos=search(arr,n,key);
	if(pos==-1){
		cout<<"Element not found";
		return n;
	}
	else{
		for(int i=pos;i<n-1;i++){
			arr[i]=arr[i+1];
		}
		return n-1;
	}
	
}
int main(){
	int arr[]={12,5,8,19,10,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Before deletion:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	int key=8;
	n=delete_key(arr,n,key);
	cout<<"\nAfter deletion:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

