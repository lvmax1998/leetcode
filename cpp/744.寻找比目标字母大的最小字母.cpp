/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        if (target >= *(--letters.end())) {
            target = 'a' - 1;
        }

        auto it = upper_bound(letters.begin(), letters.end(), target);

        return *it;
    }
};
// @lc code=end
