# memorization


#include <bits/stdc++.h>
using namespace std;

int solve(int ind , vector<int>& height , vector<int>& dp)
{
    if(ind == 0)
    {
        return 0;
    }

    if(dp[ind] != -1)
    {
        return dp[ind];
    }

    int jumptwo = INT_MAX;
    int jumpone = solve(ind-1 , height , dp) + abs(height[ind] - height[ind -1 ]);

    if(ind > 1)
    {
        jumptwo = solve(ind -2 , height , dp) + abs(height[ind] - height[ind -2]);
    }

    return dp[ind] = min(jumpone , jumptwo);



}

int main() 
{
    vector<int> height{30,10,60,10,60,50};
    int n = height.size();
    vector<int> dp(n , -1);
    cout << solve(n-1 , height , dp);

}




# vTabulation


#include <bits/stdc++.h>

using namespace std;


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}


# space optimization 


int main()
{
    vector<int> height{};
    int n = height.size();
    int prev = 0;
    int prev2 = 0;

    for(int ind = 1 ; i< n ; i++)
    {
        int jumptwo = INT_MAX;
        int jumpone = prev + abs(height[i] - height[i-1]);

        if(i>1)
        {
            jumptwo = prev2 + abs(height[i]- height[i-2]);
        }
        int curri = min(jumpone , jumptwo);
        prev2 = prev;
        prev = curri;
    }

    cout << prev;
}