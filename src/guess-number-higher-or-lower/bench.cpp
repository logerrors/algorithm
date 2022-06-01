#include "solution.hpp"
#include <benchmark/benchmark.h>


int guess(int num){
    int pick = 9;
    if(num > pick){
        return -1;
    }else if(num < pick){
        return 1;
    }else{
        return 0;
    }
}

static void BM_guessNumber(benchmark::State& state) {
  auto s = std::make_shared<Solution>();
  for (auto _ : state) {
    s->guessNumber(10000);
  }
}

BENCHMARK(BM_guessNumber);
BENCHMARK_MAIN();