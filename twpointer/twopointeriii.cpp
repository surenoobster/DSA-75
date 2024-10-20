class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int i = 0, j = 0;
        int zeros = 0;
        while(j<nums.size()) {
            while(zeros>k) if(nums[i++] == 0) zeros--;
            if(nums[j] == 0) zeros++;
            if(zeros <= k) maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};