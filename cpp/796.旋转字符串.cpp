/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        int length = s.size();
        for (int i = 0; i < length; i++) {
            string temp = s.substr(i, length - i) + s.substr(0, i);
            if (goal.compare(temp) == 0) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
