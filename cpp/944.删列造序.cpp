/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int ans = 0;
        for (size_t j = 0; j < strs[0].size(); j++) {

            for (size_t i = 0; i < strs.size() - 1; i++) {
                if (strs[i][j] > strs[i + 1][j]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
