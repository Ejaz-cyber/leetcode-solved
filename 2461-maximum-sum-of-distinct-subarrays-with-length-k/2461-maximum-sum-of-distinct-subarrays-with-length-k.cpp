class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // fail horaha
        //  [1,1,1,2,7,5]
        //  3
        
        /*
        int sum = 0;
        int maxi = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            
            if(mp[nums[i]] == 1){
                sum+=nums[i];
                cout << "sum = " << sum << "\t";
            }else {
                continue;
            }
            
            if(i >= k-1){   // window size hit hua
                
                cout << "." <<sum;
                maxi = max(sum, maxi);
                
                sum-=nums[i-k+1];
                mp[nums[i-k+1]]--;
                
                if(mp[nums[i-k+1]] == 0)
                    mp.erase(nums[i-k+1]);
                
            }

            cout << endl;
        }
        
        return maxi;
        */
        
        long long sum = 0, maxi = 0;
        int i = 0;
        unordered_map<int, int> mp;
        
        // pahla window ke liye calculation
        for(i; i<k; i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
        int len = mp.size();
        if(len == k) maxi = sum;    
        // means sara unique mila hai isiliye maxi = sum
        
        for(i = k; i<nums.size(); i++){
            mp[nums[i-k]]--;
            sum-=nums[i-k];
            
            if(mp[nums[i-k]] == 0) len--,mp.erase(nums[i-k]);
            
            if(!mp[nums[i]]) len++;
            
            mp[nums[i]]++;
            sum+=nums[i];
            
            if(len == k)
                maxi = max(maxi, sum);
            
        }
        
        return maxi;
        
        
    }
};