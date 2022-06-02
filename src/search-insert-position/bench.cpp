#include "solution.hpp"

#include <benchmark/benchmark.h>


static void BM_solution(benchmark::State& state){
    std::vector<int> nums{1,3,5,6};
    auto s = std::make_shared<Solution>();
    for (auto _ : state) {
        auto res = s->searchInsert(nums, 5);
        benchmark::DoNotOptimize(s);
    }
}

static void BM_std(benchmark::State& state){
    std::vector<int> nums{1,3,5,6};
    for (auto _ : state) {
        auto res = std::lower_bound(nums.begin(), nums.end(), 5) - nums.begin();
        benchmark::DoNotOptimize(res);
    }
}

BENCHMARK(BM_solution);
BENCHMARK(BM_std);
BENCHMARK_MAIN();