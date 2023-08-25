#include <iostream>
#include<vector>
using namespace std;


void printSub(int i,vector<int> &res, int n, int arr[]){
    if(i==n){
        for(auto el : res){
            cout<<el<<" ";
        }
        if(res.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    //adding an element 
    res.push_back(arr[i]); 
    //take
    printSub(i+1, res, n, arr);
    //remove
    res.pop_back();
    //not take
    printSub(i+1, res, n, arr);
    
}

int main()
{
    int arr[] = {3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> res;
    printSub(0, res, n, arr);
}
