/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int ans = 0;
        for (auto &&account : accounts) {
            ans = max(accumulate(account.begin(), account.end(), 0), ans);
        }

        return ans;
    }
};
// @lc code=end
