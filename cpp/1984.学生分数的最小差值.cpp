/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        if (k < 2)
            return 0;

        sort(nums.begin(), nums.end());
        int result = 999999;

        for (size_t i = 0; i + k <= nums.size(); i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }

        return result;
    }
};
// @lc code=end
