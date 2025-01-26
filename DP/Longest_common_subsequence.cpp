class Solution {
public:
   
    int f(int i , int j , string &s , string &t , vector<vector<int>>&dp){
        if(i< 0 || j<0){
            return 0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        if(s[i]  == t[j]){
            return dp[i][j] = 1 + f(i-1 , j-1 , s , t , dp);
        }
        return dp[i][j] =  max(f(i-1 , j , s , t,dp) , f(i , j-1 , s , t , dp)); 
    }

    int longestCommonSubsequence(string s1 , string s2){
        int n = s1.size();
        int m = s2.size(); 
        vector<vector<int>>dp(n , vector<int>(m ,  -1)); 
        return f(n-1 , m-1 , s1 , s2, dp);

    }

};


Ques looks like
1143. Longest Common Subsequence
Solved
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
