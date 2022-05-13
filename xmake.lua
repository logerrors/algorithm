add_rules("mode.debug", "mode.release")

set_project("algorithm")
set_languages("c++17")
set_optimize("debug")


add_includedirs("include")

add_requires("catch2", "benchmark", "fmt")

function define_test_target(name) 
    local target_name = "test-" .. name
    target(target_name)
        set_kind("binary")
        add_packages("catch2")
        add_files('src/'..name..'/test.cpp')
end

function define_bench_target(name) 
    local target_name = "bench-" .. name
    target(target_name)
        set_kind("binary")
        add_packages("benchmark")
        add_files('src/'..name..'/bench.cpp')
end

function define_target(name) 
    define_test_target(name)
    define_bench_target(name)
end

define_target("kth-largest-element-in-an-array")
define_target("reverse-linked-list")
