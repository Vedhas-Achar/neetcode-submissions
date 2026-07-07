class Solution {
   public:
    int countSubstrings(string s) {
        int count = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                count++;
                r++;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);      // odd
            expand(i, i + 1);  // even
        }

        return count;
    }
};
