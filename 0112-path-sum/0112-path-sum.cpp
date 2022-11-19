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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // checking if its a leaf node or not
        if(root != NULL){
            if(root->left == NULL && root->right == NULL)
                return (targetSum == root->val); 
            
        }else{
            return false;
        }
        
        // if root left is present
        if(hasPathSum(root->left, targetSum-root->val)){
            return true;
        }
        // if root rigth is present
        if( hasPathSum(root->right, targetSum-root->val)){
            return true;
        }
        
        return false;
    }
};