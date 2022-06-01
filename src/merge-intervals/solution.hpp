#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())return {};

        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r){
            return l[0] < r[0];
        });
        
        std::vector<std::vector<int>> merged_arr;
        for(auto i = 0; i < intervals.size(); i++){
            int L = intervals[i][0];
            int R = intervals[i][1];
            auto& last_merged_interval = merged_arr.back();
            if(merged_arr.empty() || L > last_merged_interval[1]){
                merged_arr.push_back({L, R});
            }else{
                last_merged_interval[1] = std::max(R, last_merged_interval[1]);
            }
        }
        return merged_arr;
    }
};