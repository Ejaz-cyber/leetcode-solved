//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<int> st;
        
        for(int i = 0; i<s.length(); i++){
            char c = s[i];
            if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
                st.push(c);
                
            else if(c == ')'){
                bool isRedun = true;
                
                while(st.top() != '('){
                    char top = st.top();
                    
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                        isRedun = false;
                        
                    st.pop();
                }
                
                if(isRedun) return true;
                
                st.pop();
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends