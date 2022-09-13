#include <leetcode.hpp>

using namespace leetcode;

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string res;
        for(auto i = 0;i < s.size(); i++){
            auto str1 = palindrome(s, i, i);
            auto str2 = palindrome(s, i, i+1);
            res = res.size() > str1.size() ? res : str1;
            res = res.size() > str2.size() ? res : str2;
        }
        return res;
    }

    std::string palindrome(std::string &s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};