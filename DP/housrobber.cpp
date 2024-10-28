

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(
            houseRobberHelper(vector<int>(nums.begin(), nums.end() - 1)),
            houseRobberHelper(vector<int>(nums.begin() + 1, nums.end())));
    }

private:
    int houseRobberHelper(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> lookupArray(n + 1, 0);
        lookupArray[1] = nums[0];

        for (int i = 2; i <= n; ++i) {
            lookupArray[i] =
                max(nums[i - 1] + lookupArray[i - 2], lookupArray[i - 1]);
        }

        return lookupArray[n];
    }
};




















