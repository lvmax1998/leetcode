/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include "head.h"
// @lc code=start
class RandomizedSet {
private:
    unordered_map<int, int> hash_table;
    vector<int> l;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (hash_table.count(val) <= 0) {
            l.push_back(val);
            hash_table[val] = l.size() - 1;

            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (hash_table.count(val) > 0) {
            int index = hash_table[val];
            int last = l.back();
            l[index] = last;
            hash_table[last] = index;
            l.pop_back();
            hash_table.erase(val);

            return true;
        }
        return false;
    }

    int getRandom() {
        int index = rand() % l.size();

        return l[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
