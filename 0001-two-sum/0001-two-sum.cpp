class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int , int> mp;
        vector <int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(mp.count(target - num)) {
                ans.push_back(i);
                ans.push_back(mp[target - num]);
                break;
            }
            mp[num] = i;
        }
        return ans;
    }
    
};