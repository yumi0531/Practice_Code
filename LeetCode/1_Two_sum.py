class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_map = {}
        for i in nums:
            hash_map[nums[i]] = i
            
        for i in nums:
            diff = target - nums[i]
            if (hash_map.count(diff)):
                return [i, hash_map[diff]]  