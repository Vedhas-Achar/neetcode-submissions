class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        for i in nums:
            if(nums.count(i)!= 1):
                return True
        return False