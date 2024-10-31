class Solution:
    def maxArea(self, height):
        max_area = 0
        low = 0
        high = len(height) - 1
        while low < high:
            h = min(height[low], height[high])
            b = high - low
            area = h * b
            
            if area > max_area:
                max_area = area
            
            if height[low] < height[high]:
                low += 1
            else:
                high -= 1
        
        return max_area
