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
    const int _OO = -30000005;
    int maxPathSum(TreeNode* root) {
        int ans = _OO;
        solve(root, ans);
        return ans;
    }
    int solve(TreeNode* node, int &ans) {
        if(node -> left == nullptr && node -> right == nullptr) {
            ans = max(ans , node -> val);
            return node -> val;
        }
        int left = _OO, right = _OO;
        if(node -> left != nullptr) {
            left = solve(node -> left , ans);
            ans = max(ans , left);
        }
        if(node -> right != nullptr) {
            right = solve(node -> right , ans);
            ans = max(ans , right);
        }
        ans = max({ans , node -> val + left , node -> val + right , node -> val + right + left , node -> val});
        return max({node -> val + left , node -> val + right , node -> val});
    } 
};