#include <leetcode.hpp>
#include <unordered_map>
#include <list>

using namespace leetcode;

class LRUCache
{
public:
    using kv = std::pair<int, int>;
    using list_iter = std::list<kv>::iterator;

    LRUCache(int capacity)
    {
        this->capacity_ = capacity;
    }

    int get(int key)
    {
        auto it = cache_item_map_.find(key);
        if (it == cache_item_map_.end())
        {
            return -1;
        }
        else
        {
            cache_item_list_.splice(cache_item_list_.begin(), cache_item_list_, it->second);
            return it->second->second;
        }
    }

    void put(int key, int value)
    {
        auto it = cache_item_map_.find(key);
        if (it == cache_item_map_.end())
        {
            cache_item_list_.push_front({key, value});
            cache_item_map_[key] = cache_item_list_.begin();

            if (cache_item_map_.size() > capacity_)
            {
                auto last = cache_item_list_.end();
                --last;
                cache_item_map_.erase(last->first);
                cache_item_list_.pop_back();
            }

        }
        else
        {
            it->second->second = value;
            cache_item_list_.splice(cache_item_list_.begin(), cache_item_list_, it->second);
        }
    }

private:
    std::list<kv> cache_item_list_;
    std::unordered_map<int, list_iter> cache_item_map_;
    int capacity_;
};