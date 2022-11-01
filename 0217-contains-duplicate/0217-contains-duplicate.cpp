class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int , bool> mp;
        bool ans = false;
        for(int i : nums) {
            if(mp[i]) {
                ans = true;
                break;
            }
            mp[i] = 1;
        }
        return ans;
    }
};