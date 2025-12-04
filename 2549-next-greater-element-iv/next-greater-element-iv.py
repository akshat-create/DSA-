class Solution:
    def secondGreaterElement(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [-1] * n
        stack1 = []  
        stack2 = []  
        for i, num in enumerate(nums):
           
            while stack2 and nums[stack2[-1]] < num:
                idx = stack2.pop()
                ans[idx] = num
            temp = []
            while stack1 and nums[stack1[-1]] < num:
                temp.append(stack1.pop())
            for idx in reversed(temp):
                stack2.append(idx)

           
            stack1.append(i)

        return ans

