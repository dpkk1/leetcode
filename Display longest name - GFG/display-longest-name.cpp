// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string longest(string names[], int n){
        string s="";
        int l = -1;
        for(int i=0; i<n; i++){
            // cout<<names[i].length();
            int len = names[i].length();
            if(len > l){
                l = len;
                s = names[i];
            }
        }
        return s;
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
		string names[n];
		
		for(int i=0;i<n;i++)
			cin>>names[i];
		Solution ob;
		cout<< ob.longest(names, n) << endl;
	}
}
  // } Driver Code Ends