class Solution {
public:
    
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // If k is larger than n, reduce it within the bounds of n
    
    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());
    
    // Step 2: Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);
    
    // Step 3: Reverse the remaining n-k elements
    reverse(nums.begin() + k, nums.end());
}

};



or

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // Handle cases where k is larger than the size of the array
    vector<int> temp(n);
    
    // Shift elements to their new positions
    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = nums[i];
    }
    
    // Copy the rotated array back to nums
    for (int i = 0; i < n; ++i) {
        nums[i] = temp[i];
    }
}

int main() {
    // Example 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    rotate(nums1, k1);
    for (int i : nums1) {
        cout << i << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    rotate(nums2, k2);
    for (int i : nums2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
