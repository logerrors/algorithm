#include "solution.hpp"

#include <benchmark/benchmark.h>

static void BM_solution(benchmark::State& state) {
  auto s = std::make_unique<Solution>();
  for (auto _ : state) {
    std::vector<int> arr = {0,1,0};
    auto res = s->peakIndexInMountainArray(arr);
    benchmark::DoNotOptimize(res);
  }
}

BENCHMARK(BM_solution);
BENCHMARK_MAIN();
