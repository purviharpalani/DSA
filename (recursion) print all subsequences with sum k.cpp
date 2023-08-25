#include <iostream>
#include<vector>
using namespace std;


void printSub(int i,vector<int> &res, int n, int arr[], int s, int sum){
    if(i==n){
        if(s == sum){
            for(auto el : res) cout<<el<<" ";
            cout<<endl;
        }
        return;
    }

    //adding an element 
    res.push_back(arr[i]);
    s+=arr[i];
    //take
    printSub(i+1, res, n, arr, s, sum);
    //remove
    // res.erase(remove(res.begin(), res.end(), arr[i]), res.end());
    s-=arr[i];
    res.pop_back();
    //not take
    printSub(i+1, res, n, arr, s, sum);
    
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    vector<int> res;
    printSub(0, res, n, arr, 0, k);
}
