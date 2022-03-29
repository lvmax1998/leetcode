/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int quotient, remainder;
        quotient = n / 2;
        remainder = n - 2 * quotient;

        while (quotient > 0) {
            n = quotient;
            quotient = n / 2;
            if (n - 2 * quotient == remainder)
                return false;

            remainder = n - 2 * quotient;
        }

        return true;
    }
};
// @lc code=end
