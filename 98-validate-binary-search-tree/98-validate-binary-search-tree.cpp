#define ll long long int

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
    bool solve(TreeNode* root, ll minVal, ll maxVal){
        if (root==NULL)return true;
        if (root->val<=minVal || root->val>=maxVal)return false;
        return solve(root->left,minVal,min(maxVal,(ll)root->val)) && solve(root->right,max(minVal,(ll)root->val),maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root==NULL)return true;
        return solve(root->left,LONG_MIN,root->val) && solve(root->right,root->val,LONG_MAX);
    }
};