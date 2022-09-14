#include "solution.hpp"

#include <benchmark/benchmark.h>

static void BM_solution(benchmark::State& state){
    auto s = std::make_shared<Solution>();
    for (auto _ : state) {
    std::vector<int> q1 = {1,3,-1,-3,5,3,6,7};
    std::vector<int> a1 =  {3,3,5,5,6,7};
    s->maxSlidingWindow(q1, 3);
    }
}

BENCHMARK(BM_solution);
BENCHMARK_MAIN();