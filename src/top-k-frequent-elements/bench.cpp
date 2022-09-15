#include "solution.hpp"

#include <benchmark/benchmark.h>

static void BM_solution(benchmark::State& state){
    auto s = std::make_shared<Solution>();
    for (auto _ : state) {

    }
}

BENCHMARK(BM_solution);
BENCHMARK_MAIN();