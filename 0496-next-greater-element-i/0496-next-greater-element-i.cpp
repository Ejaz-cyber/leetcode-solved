class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans(nums1.size());
        bool flag = false;
        for(int i = 0; i<nums1.size(); i++){
            int val = nums1[i];
            
            int j = 0;
            for(j; j < nums2.size(); j++){
                if(nums2[j] != val) continue;
                else break;
            }
            
            for(j; j<nums2.size(); j++){
                
                if(nums2[j] > val){
                    ans[i] = nums2[j];
                    flag = true;
                    break;
                }
            }
            
            if(!flag || j==nums2.size()) ans[i] = -1;
        }
        
        return ans;
    }
};