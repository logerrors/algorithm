#include "solution.hpp"
#include <benchmark/benchmark.h>


static void BM_binary_search(benchmark::State& state){
    auto s = std::make_shared<Solution>();
    for(auto _ : state){
        std::vector<int> t1 = {-1,0,3,5,9,12};
        s->search(t1, 9);
    }
}

static void BM_sort(benchmark::State& state){
    for(auto _: state){
        std::vector<int> t1 = {-1,0,3,5,9,12};
        std::find(t1.begin(), t1.end(), 9);
    }
}

BENCHMARK(BM_binary_search);
BENCHMARK(BM_sort);

BENCHMARK_MAIN();