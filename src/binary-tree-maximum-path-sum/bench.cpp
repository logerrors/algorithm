#include "solution.hpp"
#include <benchmark/benchmark.h>


static void example(benchmark::State& state){
    for(auto _: state){
        auto* node = leetcode::from_string<TreeNode>("[-10,9,20,null,null,15,7]");
        auto s = std::make_shared<Solution>();
        s->maxPathSum(node);
        destroy(node);
    }
}

BENCHMARK(example);

BENCHMARK_MAIN();