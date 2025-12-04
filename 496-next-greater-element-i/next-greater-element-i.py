class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        nge = {}
        
        for n in nums2:
            while stack and n > stack[-1]:
                nge[stack.pop()] = n
            stack.append(n)
        
        return [nge.get(x, -1) for x in nums1]
