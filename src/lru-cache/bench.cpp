#include "solution.hpp"

#include <benchmark/benchmark.h>


static void BM_LRU_Cache(benchmark::State& state) {
    for (auto _ : state) {
       auto s = std::make_shared<LRUCache>(2);
       s->put(2, 1);
       s->put(1, 1);
       s->put(2, 3);
       s->put(4, 1);
       s->get(1);
       s->get(2);
    }
}

BENCHMARK(BM_LRU_Cache);
BENCHMARK_MAIN();