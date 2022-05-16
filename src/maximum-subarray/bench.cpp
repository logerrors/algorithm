#include "solution.hpp"

#include <benchmark/benchmark.h>


static void BM_maxSubArray(benchmark::State& state)
{
    for(auto _:state){
        auto s = std::make_shared<Solution>();
        std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        s->maxSubArray(nums);
    }
}