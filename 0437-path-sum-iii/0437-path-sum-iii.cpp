/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #define ll long long int
    
    unordered_map<ll, int> mp;
    int count = 0;
    void countSum(TreeNode * root, int target, ll sum){
        
        if(root == NULL) return;
        
        sum += root->val;
        if(sum == target){
            count++;
        }
        
        if(mp.find(sum - target) != mp.end()){
            count += mp[sum - target];
        }
        
        mp[sum]++;
        
        countSum(root->left, target, sum);
        countSum(root->right, target, sum);
        
        mp[sum]--;
        
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        
        countSum(root, targetSum, 0);
        
        return count;
    }
};