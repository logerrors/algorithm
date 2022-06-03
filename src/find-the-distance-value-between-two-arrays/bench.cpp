#include "solution.hpp"

#include <benchmark/benchmark.h>

static void BM_solution(benchmark::State& state){
    auto solution = new Solution();
    auto arr1 = std::vector<int>{2,1,100,3};
    auto arr2 = std::vector<int>{-5,-2,10,-3,7};
    auto d = 6;
    for(auto _ : state){
        auto ret = solution->findTheDistanceValue(arr1, arr2, d);
        benchmark::DoNotOptimize(ret);
    }
    delete solution;
}

BENCHMARK(BM_solution);
BENCHMARK_MAIN();