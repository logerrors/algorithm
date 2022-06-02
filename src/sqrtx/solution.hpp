#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int L = 0;
        int R = x;
        int ans = -1;
        while(L <= R){
            long mid = L + (R - L)/2;
            if(mid * mid <= x){
                ans = mid;
                L = mid + 1;
            }else{
                R = mid - 1;
            }
        }
        return ans;
    };
};