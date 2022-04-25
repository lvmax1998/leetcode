/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int cnt = 0;
        bool is_one = false;

        while (n > 0) {
            int reminder = n % 2;

            if (reminder == 1) {
                if (!is_one) {
                    cnt = 0;
                }
                ans = max(ans, cnt);
                is_one = true;
                cnt = 1;
            } else {
                cnt++;
            }

            n /= 2;
        }

        return ans;
    }
};
// @lc code=end
