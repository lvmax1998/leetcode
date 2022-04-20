/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        }

        int ans = 9;
        for (int i = 1; i < n; i++) {
            ans *= (9 - i + 1);
        }

        return ans + countNumbersWithUniqueDigits(n - 1);
    }
};
// @lc code=end
