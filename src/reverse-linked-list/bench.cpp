#include "solution.hpp"

#include <benchmark/benchmark.h>
#include <memory>


static void reverse_linked_list(benchmark::State& state){

    auto s = std::make_shared<Solution>();

    for(auto _:state){
        state.PauseTiming();
        auto* data = leetcode::make(1000);
        state.ResumeTiming();

        s->reverseList(data);

        state.PauseTiming();
        leetcode::destory(data);
    }
}

BENCHMARK(reverse_linked_list);

BENCHMARK_MAIN();