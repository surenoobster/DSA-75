class KthLargest {
public:
priority_queue<int , vector<int> , greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        for(int x: nums)
        {
            pq.push(x);
            if(pq.size() > k){
                pq.pop()
            }        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k )
        {
            pq.pop();
        }

        return pq.top()
    }
};
