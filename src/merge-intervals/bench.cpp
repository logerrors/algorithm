#include "solution.hpp"
#include <benchmark/benchmark.h>


static void BM_Solution(benchmark::State& state) {
  auto s = std::make_shared<Solution>();
  for (auto _ : state) {
    std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    s->merge(intervals);
  }
}

BENCHMARK(BM_Solution);
BENCHMARK_MAIN();