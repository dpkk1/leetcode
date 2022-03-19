// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
   public:
    int print2largest(int a[], int n){
    	int largest=INT_MIN, secLargest = INT_MIN;
    	for(int i=0; i<n; i++){
    	    if(a[i] > largest)
    	        largest = a[i];
    	}
    	for(int i=0; i<n; i++){
    	    if(a[i] >= secLargest && a[i]!=largest)
    	        secLargest = a[i];
    	}
    	if(secLargest == INT_MIN)
    	    return -1;
    	return secLargest;
    }

};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.print2largest(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}
  // } Driver Code Ends