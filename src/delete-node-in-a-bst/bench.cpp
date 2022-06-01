#include "solution.hpp"
#include <benchmark/benchmark.h>

static void BM_deleteNode(benchmark::State &state)
{
    for (auto _ : state)
    {
        state.PauseTiming();
        auto s = std::make_shared<Solution>();
        auto test = leetcode::from_string<TreeNode>("[5,3,6,2,4,null,7]");
        state.ResumeTiming();
        s->deleteNode(test, 3);
        destroy(test);
    }
}

BENCHMARK(BM_deleteNode);

BENCHMARK_MAIN();