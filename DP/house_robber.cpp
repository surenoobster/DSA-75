class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        } 

        return dp[n - 1];        
    }
};



//Space optimization

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: If there's only one house, return its value.
        if (n == 1) {
            return nums[0];
        }

        // Initialize prev2 and prev for the first two houses.
        int prev2 = nums[0];                   // Robbing the first house.
        int prev = max(nums[0], nums[1]);      // Robbing either the first or second house.
        
        // Iterate from the third house onward.
        for (int i = 2; i < n; i++) {
            // Calculate the current maximum profit if we rob the i-th house or skip it.
            int curr = max(nums[i] + prev2, prev);
            // Update the previous values for the next iteration.
            prev2 = prev;  // Move prev to prev2.
            prev = curr;   // Move curr to prev.
        }
        
        // The last "prev" will hold the maximum amount of money that can be robbed.
        return prev;
    }
};
