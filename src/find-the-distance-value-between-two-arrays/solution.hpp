#include <leetcode.hpp>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        int count = 0;
        sort(arr2.begin(), arr2.end());
        for(auto i = 0; i < arr1.size();i++){
            if(binarySearch(arr2, arr1[i], d)){
                count++;
            }
        }
        return count;
    }

private:
    inline bool binarySearch(std::vector<int>& arr, int target, int d){
        int L = 0;
        int R = arr.size() - 1;
        while(L <= R){
            int mid = L + (R - L)/2;
            if(arr[mid] >= target){
                int delta = arr[mid] - target;
                if(delta <= d){
                    return false;
                }else{
                    R = mid - 1;
                }
            }else{
                int delta = target - arr[mid];
                if(delta <= d){
                    return false;
                }else{
                    L = mid + 1;
                }
            }
        }

        return true;
    }
};