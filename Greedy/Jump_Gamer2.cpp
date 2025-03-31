#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, farthest = 0, currentEnd = 0;
    
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        
        if (i == currentEnd) { // Need to jump
            jumps++;
            currentEnd = farthest;
        }
    }
    
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << jump(nums) << endl;
    return 0;
}
