// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// function to return sum of  1, 2, ... n
	long long seriesSum(int n) {
	    // code here
	   long long sum= (((long long)n)*((long long)(n+1)))/2;
       return sum;
	}
};

// { Driver Code Starts.

int main() {
    int t;https://media.geeksforgeeks.org/img-practice/play-1596780125.svg
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.seriesSum(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends