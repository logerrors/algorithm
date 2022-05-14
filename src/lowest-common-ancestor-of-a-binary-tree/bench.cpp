#include "solution.hpp"

#include <benchmark/benchmark.h>

static void example(benchmark::State& state){
    for(auto _ : state){
        auto s = std::make_shared<Solution>();
        auto *root = leetcode::from_string<TreeNode>("[3,5,1,6,2,0,8,null,null,7,4]");
        auto *p = find(root, 5);
        auto *q = find(root, 1);
        auto *expect = find(root, 3);
        auto *ret = s->lowestCommonAncestor(root, p, q);
        assert(expect == ret);
    }
}

BENCHMARK(example);
BENCHMARK_MAIN();