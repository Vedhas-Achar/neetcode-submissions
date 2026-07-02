class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int big = 0;

        while(left < right){
            int area = min(heights[left], heights[right]) * (right - left);

            big = max(big, area);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        } 
        return big;

    }
};
