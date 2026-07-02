class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int>map;
        
        for(const auto& num:nums){
            map[num]++;
        }
        vector<pair<int,int>> v(map.begin(), map.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b){
            return a.second>b.second;
        });
        for(int i = 0; i<k; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};
