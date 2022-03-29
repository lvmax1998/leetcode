/*
 * @lc app=leetcode.cn id=2029 lang=cpp
 *
 * [2029] 石子游戏 IX
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    bool stoneGameIX(vector<int> &stones) {
        vector<int> cnt(3, 0);

        for (auto &&stone : stones) {
            cnt[stone % 3]++;
        }

        return true;
    }
};
// @lc code=end
