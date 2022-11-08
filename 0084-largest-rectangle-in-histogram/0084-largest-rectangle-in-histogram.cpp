class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int leftSmall[n], rightSmall[n];
        
        // left small
        for(int i = 0; i<n; i++){
            
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            
            if(st.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = st.top() + 1;
            
            st.push(i);
        }
        
        // clear up stack for reuse
        while(st.empty() == false) st.pop();
        
        // right small
        for(int i = n-1; i>=0; i--){
            
            while(st.empty() == false && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty()) rightSmall[i] = n-1;
            else rightSmall[i] = st.top() - 1;
            
            st.push(i);
        }
        
        
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            
            int length = rightSmall[i] - leftSmall[i] + 1;
            maxArea = max(maxArea, heights[i]*length);
        }
        
        return maxArea;
        
        
        
    }
};