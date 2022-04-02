/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        int s;

        for (int num = left; num <= right; num++) {
            bool flag = true;

            int s = num % 10;
            int t = num / 10;
            while (t != 0) {
                if (s == 0 || num % s != 0) {
                    flag = false;
                    break;
                }

                s = t % 10;
                t = t / 10;
            }

            if (flag && s != 0 && num % s == 0) {
                ans.emplace_back(num);
            }
        }

        return ans;
    }
};
// @lc code=end
