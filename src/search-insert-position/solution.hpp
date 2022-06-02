#include "leetcode.hpp"

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int res = 0;

        for(; L <= R;){
            int mid = L + (R - L)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                res = mid + 1;
                L = res;
            }else{
                R = mid - 1;
            }
        }
        return res;
    }
};