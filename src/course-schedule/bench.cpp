#include "solution.hpp"
#include <benchmark/benchmark.h>

static void BM_course_schedule(benchmark::State &state)
{

    for (auto _ : state)
    {
        auto s = std::make_shared<Solution>();
        int  n = 2;
        std::vector<std::vector<int>> arr = {{1,0},{0,1}};
        s->canFinish(n , arr);
    }
}

BENCHMARK(BM_course_schedule);

BENCHMARK_MAIN();