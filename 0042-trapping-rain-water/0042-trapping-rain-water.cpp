class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        int maxi = INT_MIN;
        
        for(int i = 0; i<n; i++){
            if(height[i] > maxi){
                maxi = height[i];
            }
            maxLeft[i] = maxi;
        }
        
        maxi = INT_MIN;
        for(int i = n-1; i>=0; i--){
            if(height[i] > maxi){
                maxi = height[i];
            }
            maxRight[i] = maxi;
        }
        
        int sum = 0;
        for(int i = 0; i<n; i++){
             //sum of all water stored on single tower
            sum+= min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return sum;
    }
};