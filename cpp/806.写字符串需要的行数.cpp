/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int> &widths, string s) {
        int row = 1;
        int current_width = 0;
        for (auto &&c : s) {
            int width = widths[c - 'a'];
            if (current_width + width > 100) {
                current_width = width;
                row++;
            } else {
                current_width += width;
            }
        }

        return {row, current_width};
    }
};
// @lc code=end
