class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<  vector <int> > st;
        sort(arr.begin() , arr.end() , [](const vector <int> a, const vector <int> b) {return a[0] < b[0]; });
        int sz = arr.size();
        for(int i = 0; i < sz; i++) {
            if(st.empty()) {
                st.push_back(arr[i]);
                continue;
            }
            if(st.back()[1] >= arr[i][0]) {
                vector <int> cur = {st.back()[0] , max(arr[i][1] , st.back()[1])};
                st.pop_back();
                st.push_back(cur);
            } else st.push_back(arr[i]);
        }
        return st;
    }
};