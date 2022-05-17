#include <leetcode.hpp>

using namespace leetcode;

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> char_map;
        int left = 0;
        int res = 0;
        for(auto right = 0; right < s.size(); right++){
            if(char_map.find(s[right]) != char_map.end()){
                left = std::max(left, char_map[s[right]] + 1);
            }
            char_map[s[right]] = right;
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};