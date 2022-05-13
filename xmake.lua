add_rules("mode.debug", "mode.release")

set_project("algorithm")
set_languages("c++17")
set_optimize("debug")

add_requires("catch2", "benchmark", "fmt")

target("test-kth-largest-element-in-an-array")
    set_kind("binary")
    add_packages("catch2")
    add_files('src/kth-largest-element-in-an-array/test.cpp')

target("bench-kth-largest-element-in-an-array")
    set_kind("binary")
    add_packages("benchmark")
    add_files('src/kth-largest-element-in-an-array/bench.cpp')
