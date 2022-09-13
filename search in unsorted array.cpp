//search in an unsorted array
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
int main(){
	int arr[]={12,5,8,19,10,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=7;
	int found=search(arr,n,key);
	if(found==-1){
		cout<<key<<" not found in the array";
	}
	else{
		cout<<key<<" found at "<<found<<" index";
	}
	return 0;
}

