#include "leetcode.hpp"

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int L = 1;
        int R = arr.size() - 1;
        int res = 0;

        while(L <= R){
            int mid = L + (R - L) / 2;
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                return mid;
            }else if(arr[mid] > arr[mid+1]){
                R = mid - 1;
            }else if(arr[mid] > arr[mid-1]){
                L = mid + 1;
            }
        }
        return res;
    }
};