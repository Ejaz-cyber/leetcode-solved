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
    bool ans;
    int doMagic(TreeNode * root){
        if(root == NULL){
            return 0;
        }
        // if Answer is already false then return it
        if(ans == false){
            return 0;
        }
        
        int leftHeight = doMagic(root->left);
        int rightHeight = doMagic(root->right);
        
        if(abs(leftHeight - rightHeight) > 1){  // not balanced
            ans = false;
        }
        
        return 1 + max(leftHeight, rightHeight);
        
    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        
        int temp = doMagic(root);
        
        return ans;
        
    }
};