class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> nge(n);
        
        for(int i = 2*n - 1; i>=0; i--){
            int num = nums[i%n];
            while(!st.empty() && st.top() <= num) st.pop();
            
            if(i < n){
                if(!st.empty())
                    nge[i] = st.top(); 
                else
                    nge[i] = -1;
                
            }
            
            st.push(num);
        }
        
        
        return nge;
    }
};