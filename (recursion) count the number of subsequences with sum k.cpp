#include <iostream>
#include<vector>
using namespace std;


int printSub(int i, int n, int arr[], int s, int sum){
    if(i==n){
        //condition satisfied
        if(s == sum)
            return 1;
        else
            return 0;
    }

    //adding an element 
    s+=arr[i];
    //take
    int l = printSub(i+1, n, arr, s, sum);
    //remove
    s-=arr[i];
    //not take
    int r = printSub(i+1, n, arr, s, sum);
    
    return l+r;
    
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<printSub(0, n, arr, 0, k);
}
