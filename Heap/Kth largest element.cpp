class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0 ;i <n ; i++)
        {
            pq.push(nums[i]);
        }
        int tobepop = k-1;
        while(tobepop >0 )
        {
            pq.pop();
            tobepop --;
        }
        return pq.top();
    }
};





