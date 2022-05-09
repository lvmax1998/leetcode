/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int length = s.size();

        vector<int> ans(length + 1);
        int max_num = length, min_num = 0;

        for (size_t i = 0; i < length; i++) {
            char c = s[i];
            if (c == 'I') {
                ans[i] = min_num++;
            } else if (c == 'D') {
                ans[i] = max_num--;
            }
        }

        ans[length] = max_num;

        return ans;
    }
};
// @lc code=end
