int knapsackutil(vector<int>& wt , vector<int>& val , int ind , int W , vector<vector<int>>& dp)
{
    if(ind ==0 || W ==0)
    {
        return 0;
    }

    if(dp[ind][W] != -1)
    {
        return dp[ind][W];
    }


    int nottaken = knapsackutil(wt,val,ind -1 , W , dp);
    int taken = 0;

    if (wt[ind] <= W)
    {
        taken = val[ind] + knapsackutil(wt , val , ind-1 , W-wt[ind] ,dp);
    }


    return dp[ind][W] = max(nottaken , taken);



}