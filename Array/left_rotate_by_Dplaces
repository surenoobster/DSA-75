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








class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
       reverse(nums,0,(nums.size())-1);
        reverse(nums, 0 , k-1);
        reverse(nums, k,(nums.size())-1);

    }
    void reverse(vector<int>& nums, int start, int end){
        
        int temp;
        while(start<end){
            temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            end--;
            start++;
        }
    }
        
};




"""The while loop runs as long as start is less than end. This ensures that elements at the beginning of the subarray are swapped with elements at the end of the subarray.
Swap operation:
temp = nums[start];: Temporarily store the value at index start.
nums[start] = nums[end];: Place the value at index end into the position at start.
nums[end] = temp;: Place the stored value (temp, which was originally at start) into the position at end.
After the swap, the start index is incremented, and the end index is decremented, moving both pointers towards the center of the array.
The loop continues until start becomes equal to or greater than end, meaning all the pairs of elements in the given range have been swapped.
Example Walkthrough:
Suppose the vector nums = {1, 2, 3, 4, 5} and you call reverse(nums, 1, 3). Here's how the function will work step by step:

Initial State: nums = {1, 2, 3, 4, 5}, start = 1, end = 3

First iteration:

Swap nums[1] and nums[3]:
temp = nums[1] = 2
nums[1] = nums[3] = 4
nums[3] = temp = 2
Array after first iteration: {1, 4, 3, 2, 5}
Increment start to 2 and decrement end to 2.
Second iteration:

Now start == end, which means the while loop condition start < end is no longer true, so the loop stops.
Final State: The subarray from index 1 to 3 has been reversed: {1, 4, 3, 2, 5}.

How It Works in the Main Function:
In your rotate function, you use the reverse function three times to rotate the array. Here’s how each call works:

First call: reverse(nums, 0, nums.size()-1);
This reverses the entire array.
Second call: reverse(nums, 0, k-1);
This reverses the first k elements.
Third call: reverse(nums, k, nums.size()-1);
This reverses the remaining n-k elements from index k to the end.
By combining these three reversals, the array is effectively rotated by k positions. This is a space-efficient way of rotating the array because it only uses a constant amount of extra space."""



