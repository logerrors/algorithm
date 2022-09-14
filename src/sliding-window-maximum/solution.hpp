#include "leetcode.hpp"
#include <deque>

using namespace leetcode;

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<int> que;

        for(auto i = 0; i < k; i++){
            while(!que.empty() && nums[i] > que.back()){
                que.pop_back();
            }
            que.push_back(nums[i]);
        }

        res.push_back(que.front());

        for(auto right = k; right < nums.size(); right++){

            // 取窗口左端
            int left = nums[right - k];

            // 窗口移动时左端需要判断是否更新单调队列
            if(!que.empty() && left == que.front()){
                que.pop_front();
            }

            // 窗口移动时右端需要判断是否需要更新单调队列
            while(!que.empty() && nums[right] > que.back()){
                que.pop_back();
            }
            que.push_back(nums[right]);

            // 获取单调队列中的最大值
            res.push_back(que.front());
        }

        return res;
    }
};