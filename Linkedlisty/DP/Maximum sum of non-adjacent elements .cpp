#include <bits/stdc++.h>

using namespace std;

int solveutil(int ind , vector<int>& arr , vector<ind>& dp)
{
if(dp[ind] != -1)
{
    return dp[ind];
}
    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;
int Pick = arr[ind] + solveUtil(ind -2 , arr , dp); // kyunki 
int nonPick = 0 + solveUtil(ind - 1 , arr , dp);

return dp[ind] =   max(pick , nonPick);


}


int solution(int n , vector<int> &arr)
{
vector<int> dp(n,-1);
return solveutil(n-1 , arr , dp);

}


int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    
    // Call the solve function and print the result
    cout << solution(n, arr);

    return 0;
}