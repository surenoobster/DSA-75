class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures)
        stack = []

        for day, temp in enumerate(temperatures):
            while stack and temp > temperatures[stack[-1]]:
                last_day = stack.pop()
                ans[last_day] = day - last_day
            stack.append(day)
        return ans