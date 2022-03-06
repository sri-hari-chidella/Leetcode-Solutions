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
    vector<int> rightSideView(TreeNode* root) {
        unordered_set<int> seen;
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        if (root==NULL)return ans;
        q.push({root,0});
        while (!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;q.pop();
            if (seen.find(level)==seen.end()){
                seen.insert(level);
                ans.push_back(node->val);
            }
            else{
                ans[level]=node->val;
            }
            if (node->left!=NULL)q.push({node->left,level+1});
            if (node->right!=NULL)q.push({node->right,level+1});
        }
        return ans;
    }
};