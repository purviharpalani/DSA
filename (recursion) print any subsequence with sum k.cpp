#include <iostream>
#include<vector>
using namespace std;


bool printSub(int i,vector<int> &res, int n, int arr[], int s, int sum){
    if(i==n){
        //condition satisfied
        if(s == sum){
            for(auto el : res) cout<<el<<" ";
            cout<<endl;
            return true;
        }
        else
        return false;
    }

    //adding an element 
    res.push_back(arr[i]);
    s+=arr[i];
    //take
    if(printSub(i+1, res, n, arr, s, sum) == true) return true;
    //remove
    // res.erase(remove(res.begin(), res.end(), arr[i]), res.end());
    s-=arr[i];
    res.pop_back();
    //not take
    if(printSub(i+1, res, n, arr, s, sum) == true) return true;
    
    return false;
    
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    vector<int> res;
    printSub(0, res, n, arr, 0, k);
}
