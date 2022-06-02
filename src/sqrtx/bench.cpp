#include "solution.hpp"

#include <cmath>
#include <benchmark/benchmark.h>

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;						// evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

#ifndef Q3_VM
#ifdef __linux__
	assert( !isnan(y) ); // bk010122 - FPE?
#endif
#endif
	return y;
}


static void BM_mySqrt(benchmark::State& state) {
    auto s = std::make_shared<Solution>();
    for (auto _ : state) {
        s->mySqrt(1233422.0f);
    }
}

static void BM_sqrt(benchmark::State& state){
    for (auto _ : state) {
        std::sqrt(1233422.0f);
    }
}

static void BM_Qsqrt(benchmark::State& state){
    for (auto _ : state) {
        Q_rsqrt(1233422.0f);
    }
}

// BENCHMARK(BM_mySqrt);
BENCHMARK(BM_sqrt);
BENCHMARK(BM_Qsqrt);
BENCHMARK_MAIN();