#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map to store groups of anagrams
        unordered_map<string, vector<string>> anagramGroups;

        // For each string in the input list
        for (const string& str : strs) {
            // Sort the string to get the key
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // Add the original string to the corresponding anagram group
            anagramGroups[sortedStr].push_back(str);
        }

        // Collect all groups of anagrams from the hash map
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};
