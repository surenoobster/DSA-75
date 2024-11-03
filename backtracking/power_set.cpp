class Solution {
public:
    // Helper function for backtracking
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(subset);
        
        // Loop through the array elements starting from 'start'
        for (int i = start; i < nums.size(); i++) {
            // Include nums[i] in the current subset
            subset.push_back(nums[i]);
            
            // Recursively call backtrack with the next index
            backtrack(nums, i + 1, subset, result);
            
            // Exclude nums[i] from the current subset (backtrack)
            subset.pop_back();
        }
    }
    
    // Main function to generate all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> subset;          // Temporary subset
        backtrack(nums, 0, subset, result);
        return result;
    }
};
