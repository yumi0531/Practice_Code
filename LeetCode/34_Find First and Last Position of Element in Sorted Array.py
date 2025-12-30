class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start = findBound(nums=nums, target=target, is_find_start=True)
        if start == -1:
            return [-1, -1]
        end = findBound(nums=nums, target=target, is_find_start=False)
        
        return [start, end]
        
        
def findBound(nums, target, is_find_start):
    left, right = 0, len(nums) - 1
    bound = -1
    
    while left <= right:
        mid = (left + right) // 2
        
        if nums[mid] == target:
            bound = mid
            if is_find_start:
                right = mid - 1
            else:
                left = mid + 1
        elif (nums[mid] < target):
            left = mid + 1
        else:
            right = mid - 1
    
    return bound 
        
    
    
    
                









if __name__ == "__main__":
    sol = Solution()


    test_cases = [
        {"nums": [5, 7, 7, 8, 8, 10], "target": 8, "expected": [3, 4]},
        {"nums": [5, 7, 7, 8, 8, 10], "target": 6, "expected": [-1, -1]},
        {"nums": [], "target": 0, "expected": [-1, -1]},
    ]

    print(f"{'Input Nums':<25} | {'Target':<7} | {'Output':<10} | {'Status'}")
    print("-" * 60)

    for i, case in enumerate(test_cases):
        nums = case["nums"]
        target = case["target"]
        expected = case["expected"]
        
        result = sol.searchRange(nums, target)
        
        status = "Pass" if result == expected else "Fail"
        print(f"{str(nums):<25} | {target:<7} | {str(result):<10} | {status}")