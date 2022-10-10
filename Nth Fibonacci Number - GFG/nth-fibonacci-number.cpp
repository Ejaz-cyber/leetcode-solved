//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        // using tabulation method O(n) O(1)
        long long prev = 1;
        long long prev2 = 0;
        long long curr;
        for(int i =2; i<=n; i++){
            curr = (prev+prev2)%1000000007;
            prev2 = prev;
            prev = curr;
            
        }
        
        return curr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends