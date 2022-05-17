#include "solution.hpp"

#include <benchmark/benchmark.h>


static void BM_Solution(benchmark::State& state) {
  auto s = std::make_shared<Solution>();
  for (auto _ : state) {
    auto input = "abcabcbb";
    s->lengthOfLongestSubstring(input);
  }
}

BENCHMARK(BM_Solution);
BENCHMARK_MAIN();