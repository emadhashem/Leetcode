class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset <pair <int , vector <int> > > st;
        for(auto cur : points) {
            st.insert({ (cur[0] * cur[0]) + (cur[1] * cur[1]) , {cur[0] , cur[1]}});
        }
        vector <vector <int> > ans;
        for(auto cur : st) {
            if(!k) break;
            ans.push_back(cur.second);
            k--;
        }
        return ans;
        
    }
};