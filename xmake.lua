add_rules("mode.debug", "mode.release")

set_project("algorithm")
set_languages("c++17")
set_optimize("debug")

add_includedirs("include")

add_requires("catch2", "benchmark")

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
define_target("binary-tree-maximum-path-sum")
define_target("lowest-common-ancestor-of-a-binary-tree")
define_target("delete-node-in-a-bst")
define_target("lru-cache")
define_target("maximum-subarray")
define_target("leetcode")
define_target("longest-substring-without-repeating-characters")
define_target("course-schedule")
define_target("serialize-and-deserialize-binary-tree")
define_target("merge-intervals")
define_target("binary-search")
define_target("guess-number-higher-or-lower")
define_target("sqrtx")
define_target("search-insert-position")
define_target("peak-index-in-a-mountain-array")
define_target("find-the-distance-value-between-two-arrays")
define_target("longest-palindromic-substring")


task("problem")

    set_category("plugin")

    on_run(function()
        -- 导入参数选项模块
        import("core.base.option")

        local title = option.get('title')
        local src_dir = "$(projectdir)/src/"..title
        if os.exists(src_dir) then 
            print(src_dir.." has exist!!!")
        else
            os.mkdir(src_dir)
            os.cd(src_dir)
            os.run("touch solution.hpp")
            os.run("touch test.cpp")
            os.run("touch bench.cpp")
            os.cd('-')
        end 
    end)

    set_menu {
        usage = "xmake problem title" ,

        description = "create leetcode problem template" ,

        options = 
        {
            {nil, "title", "v", nil, "the problem title"}
        }
    }