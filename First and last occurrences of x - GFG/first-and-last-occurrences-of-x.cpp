// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

vector<int> find(int a[], int n , int x ){
    vector<int>v;
    int low=0;
    int high = n-1;
    int res=-1, ans=-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(a[mid] == x){
            res = mid;
            high = mid-1;
        }
        else if(x < a[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    low = 0;
    high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(a[mid] == x){
            ans = mid;
            low = mid+1;
        }
        else if(a[mid] > x)
            high = mid-1;
        else
            low = mid+1;
    }
    v.push_back(res);
    v.push_back(ans);
    return v;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends