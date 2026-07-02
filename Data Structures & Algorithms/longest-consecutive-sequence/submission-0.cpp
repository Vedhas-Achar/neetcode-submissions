class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int big = 0;
        for(auto n : nums){
            int len = 0;
            while(find(nums.begin(), nums.end(), n++) != nums.end()){
                len++;
            }
            big = (len > big)?len:big;
        }
        return big;
    }
};
