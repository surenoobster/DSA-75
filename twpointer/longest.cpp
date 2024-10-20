class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;

        unordered_set<char> charSet;
        int left = 0; // Pointer to the left of the sliding window
        int maxans = 0; // To store the maximum length of the substring

        for (int right = 0; right < s.length(); right++) { // right pointer traversing the string
            while (charSet.find(s[right]) != charSet.end()) { // If character is already in the set
                charSet.erase(s[left]); // Remove the leftmost character
                left++; // Move the left pointer to shrink the window
            }
            charSet.insert(s[right]); // Insert the current character into the set
            maxans = max(maxans, right - left + 1); // Update the maximum length
        }

        return maxans;
    }
};



//another method

