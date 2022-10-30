class Solution {
public:
    vector<int> nSmallest(vector<int> &arr){
        stack<int> st;
        st.push(-1);
        int n = arr.size();
        vector<int> ans(n);
        
        for(int i = n-1; i>=0; i--){
            
            while(st.top() != -1 && arr[i] <= arr[st.top()])
                st.pop();
            
            if(st.top() == -1)
                ans[i] = n;
            else ans[i] = st.top();
            
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> pSmallest(vector<int> &arr){
        stack<int> st;
        st.push(-1);
        int n = arr.size();
        vector<int> ans(n);
        
        for(int i = 0; i<n; i++){
            
            while(st.top() != -1 && arr[i] <= arr[st.top()]) st.pop();
            
            ans[i] = st.top();
            
            st.push(i);
        }
        
        return ans;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ns = nSmallest(heights);     
        vector<int> ps = pSmallest(heights);

        int size = heights.size();
        
        vector<int> bre(size);
        for(int i = 0; i<ns.size(); i++){
            bre[i] = ns[i] - ps[i] -1;
        }
        
        int maxArea = INT_MIN;
        for(int i = 0; i<size; i++){
            int l = heights[i];
            int b = bre[i];
            
            maxArea = max(maxArea, l*b);
        }
        
        
        
        return maxArea;
    }
};