#include "leetcode.hpp"

using namespace leetcode;


class Compare{
    public:
        bool operator()(const std::pair<int,int>& lhs, const std::pair<int,int>& rhs){
            return lhs.second > rhs.second;
        }
};

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> map;
        for(auto num:nums){
            map[num]++;
        }

        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Compare> pq;
        for(auto item:map){
             pq.push(item);
            if(pq.size() > k){
                pq.pop();
            }
        }

        std::vector<int> res(k);
        for(int i = k - 1; i >= 0 ; i--){
            res[i] = pq.top().first;
            pq.pop();
        }

        return res;
    }
};