#include <benchmark/benchmark.h>

#include "solution.hpp"


static void solution(benchmark::State& state) {
  auto s = std::make_shared<Solution>();
  srand(time(NULL));

  for (auto _ : state) {
    state.PauseTiming();
    int size = rand() % 10000;
    int k = rand() % 1000;
    vector<int> data;
    data.resize(size);
    for(auto i = 0; i < size; i++){
        data[i] = rand() % 200000;
    }
    state.ResumeTiming();
    s->findKthLargest(data, k);
  }
}

static void std_sort(benchmark::State& state) {
  srand(time(NULL));
  for (auto _ : state) {
    state.PauseTiming();
    int size = rand() % 10000;
    int k = rand() % 1000;
    vector<int> data;
    data.resize(size);
    for(auto i = 0; i < size; i++){
        data[i] = rand() % 200000;
    }
    state.ResumeTiming();
    std::sort(data.begin(), data.end());
  }
}

// Register the function as a benchmark
BENCHMARK(solution);
BENCHMARK(std_sort);
// Run the benchmark
BENCHMARK_MAIN();