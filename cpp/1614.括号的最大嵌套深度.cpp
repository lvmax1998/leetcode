/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */
#include "head.h"
// @lc code=start
class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0, cnt = 0;
        for (auto &&x : s)
        {
            if (x == '(')
            {
                cnt += 1;
            }
            else if (x == ')')
            {
                cnt -= 1;
            }

            depth = max(depth, cnt);
        }

        return depth;
    }
};
// @lc code=end
