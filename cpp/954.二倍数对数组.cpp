/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> counter;
        for (auto &&it : arr) {
            counter[it]++;
        }

        sort(arr.begin(), arr.end(), [](int &x, int &y) { return abs(x) < abs(y); });
        for (auto i = arr.begin(); i < arr.end(); i++) {
            auto it = *i;
            if (counter.count(it) == 0) {
                continue;
            }
            counter[it]--;
            if (counter[it] == 0) {
                counter.erase(it);
            }

            if (counter.count(2 * it) == 0) {
                return false;
            }
            counter[2 * it]--;
            if (counter[2 * it] == 0) {
                counter.erase(2 * it);
            }
        }

        return true;
    }
};
// @lc code=end
