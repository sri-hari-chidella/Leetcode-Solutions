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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while (!q.empty()){
            TreeNode* curr=q.front().first;int level=q.front().second;q.pop();
            if (curr==NULL)continue;
            mp[level].push_back(curr->val);
            q.push({curr->left,level+1});
            q.push({curr->right,level+1});
        }
        vector<vector<int>> ans;
        for (auto i:mp)ans.push_back(i.second);
        return ans;
    }
};