#include <leetcode.hpp>

class Solution
{
public:
    int maxSubArray(std::vector<int> &num)
    {
        int max_sum = num[0];
        int cur = 0;

        for(auto i = 0; i < num.size(); i++){
            cur = std::max(cur + num[i], num[i]);
            max_sum = std::max(max_sum, cur);
        }
        return max_sum;
    }
};