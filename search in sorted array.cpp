//search in a sorted array
//Time Complexity of Search Operation: O(log(n)) [Using Binary Search] 
//Auxiliary Space: O(log(n)) due to recursive calls

#include<iostream>
using namespace std;

int binary_search(int arr[],int low,int high,int key){
	int mid=(low+high)/2;
	if(key==arr[mid])
		return mid;
	if(key>arr[mid])
		return binary_search(arr,(mid+1),high,key);
	return binary_search(arr,low,(mid-1),key);
	
}

int main(){
	int arr[]={2,5,6,8,10,13,17,20};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=13;
	int pos= binary_search(arr,0,n-1,key);
	if(pos==-1){
		cout<<"not found";
	}
	else{
		cout<<"Element found at index "<<pos;
	}
}
