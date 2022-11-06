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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int> > ans;
        if(root != nullptr) solve(ans , root);
        return ans;
    }
    void solve(vector <vector <int> > &ans , TreeNode* node) {
        
        int lvl = 1;
        ans.push_back({node -> val});
        deque <TreeNode*> q;
        q.push_back(node);
        int sz = q.size();
        vector <int> lvl_val;
        while(!q.empty()) {
            
            TreeNode* cur;
            if(lvl & 1) {
                cur = q.front();
                q.pop_front();
            }
            else {
                cur = q.back();
                q.pop_back();
            }
            
            sz--;
            TreeNode* lft = cur -> left;
            TreeNode* rght = cur -> right;
            if(lvl & 1) {
                if(check_is_null(rght)) {
                    lvl_val.push_back(rght -> val);
                    q.push_back(rght);
                }
                if(check_is_null(lft)) {
                    lvl_val.push_back(lft -> val);
                    q.push_back(lft);
                }
            } else {
                
                if(check_is_null(lft)) {
                    lvl_val.push_back(lft -> val);
                    q.push_front(lft);
                }
                if(check_is_null(rght)) {
                    lvl_val.push_back(rght -> val);
                    q.push_front(rght);
                }
            }
            if(sz == 0) {
                sz = q.size();
                lvl++;
                if(lvl_val.size()) ans.push_back(lvl_val);
                lvl_val.clear();
            }
        }
    }
    bool check_is_null(TreeNode* node) {
        return node != nullptr;
    }
};