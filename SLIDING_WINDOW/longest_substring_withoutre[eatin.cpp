class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> lastSeen;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            maxLength = max(maxLength, right - left + 1);
            lastSeen[c] = right;
        }

        return maxLength;        
    }
};


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        left = 0
        last_seen = {}

        for right in range(len(s)):
            c = s[right]
            if c in last_seen and last_seen[c] >= left:
                left = last_seen[c] + 1
            max_length = max(max_length, right - left + 1)
            last_seen[c] = right

        return max_length
