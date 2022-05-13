#include <vector>
#include <memory>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(nullptr));
        quick_sort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
private:
    void quick_sort(vector<int> &nums, int left, int right){
        if(left < right){
            int p = partition(nums, left, right);
            quick_sort(nums, left, p - 1);
            quick_sort(nums, p + 1, right);
        }
    }

    int partition(vector<int> &nums, int left, int right){
        int pivot_position = rand() % (right - left) + left;
        std::swap(nums[pivot_position], nums[right]);

        int pivot = nums[right];
        int i = left;
        int j = left;
        for(;j < right; j++){
            if(nums[j] < pivot){
                std::swap(nums[j], nums[i]);
                i++;
            }
        }
        std::swap(nums[i], nums[right]);

        assert(i == pivot_position);
        return i;
    }
};