#include "solution.hpp"

#include <benchmark/benchmark.h>

static void BM_solution(benchmark::State& state){
    auto s = std::make_shared<Solution>();
    for (auto _ : state) {
        std::vector q = {1,1,1,2,2,3};
        s->topKFrequent(q, 2);
    }
}

BENCHMARK(BM_solution);
BENCHMARK_MAIN();