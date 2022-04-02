/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int strongPasswordChecker(string password) {
        int result = 0;
        int length = password.size();

        vector<int> diff(3, 0);
        for (auto &&c : password) {
            if (c >= 'a' && c <= 'z') {
                diff[0] = 1;
            } else if (c >= 'A' && c <= 'Z') {
                diff[1] = 1;
            } else if (c >= '0' && c <= '9') {
                diff[2] = 1;
            }
        }
        int cls = diff[0] + diff[1] + diff[2];

        if (length < 6) {
            return max(6 - length, 3 - cls);
        } else if (length >= 20) {
            return (length - 20) + (3 - cls);
        }

        return 3 - cls;
    }
};
// @lc code=end
