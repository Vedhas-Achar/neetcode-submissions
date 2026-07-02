class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++){
            if(seen[s[right]] >= left){
                left = seen[s[right]] + 1;
            }
            seen[s[right]] = right;
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
