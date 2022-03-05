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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while (!q.empty()){
            TreeNode* temp=q.front().first;int row=q.front().second.first;int col=q.front().second.second;q.pop();
            if (temp==NULL)continue;
            mp[col].push_back({row,temp->val});
            q.push({temp->left,{row+1,col-1}});
            q.push({temp->right,{row+1,col+1}});
        }
        for (auto i:mp){
            sort(i.second.begin(),i.second.end());
            vector<int> temp;
            for (int j=0;j<i.second.size();j++){
                temp.push_back(i.second[j].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};