class Solution {
public:
    void backtrack(int open, int close, int n, string current, vector<string>& result) {
        // If the current combination has reached the max length (2 * n), add it to the result.
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // If we can still add an opening bracket, add it and recurse.
        if (open < n) {
            backtrack(open + 1, close, n, current + '(', result);
        }
        
        // If we can add a closing bracket (i.e., if there are unmatched opening brackets), add it and recurse.
        if (close < open) {
            backtrack(open, close + 1, n, current + ')', result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};
