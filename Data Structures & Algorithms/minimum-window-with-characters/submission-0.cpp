class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        unordered_map<char, int> need, window;
        for(char c:t) need[c]++;
        
        int have = 0;
        int minlen = INT_MAX, start = 0;
        int l = 0;

        for(int r = 0; r<s.size(); r++){
            char c = s[r];
            window[c]++;

            if(need.count(c) && window[c] == need[c]) have++;

            while(have == need.size()){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    start = l;
                }

                char left = s[l];
                window[left]--;

                if(need.count(left) && window[left] < need[left]) have--;
                l++;
            }
        }
        return minlen == INT_MAX ? "":s.substr(start, minlen);
    }
};
