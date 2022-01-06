/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */
#include "head.h"
// @lc code=start
class Solution
{
public:
    string modifyString(string s)
    {
        int pos = s.find('?');
        if (pos == string::npos)
            return s;

        int length = s.length();

        while (pos != length && s[pos] == '?')
        {
            pos++;
        }

        if (pos != length)
        {
            if (pos - 2 < 0 || s[pos - 2] == '?' || s[pos - 2] != 'a' + (s[pos] - 'a' + 1) % 26)
                s[pos - 1] = 'a' + (s[pos] - 'a' + 1) % 26;
            else
                s[pos - 1] = 'a' + (s[pos] - 'a' + 2) % 26;
        }
        else
        {
            if (pos - 2 < 0 || s[pos - 2] == '?')
                s[pos - 1] = 'a';
            else
                s[pos - 1] = 'a' + (s[pos - 2] + 1 - 'a') % 26;
        }

        return modifyString(s);
    }
};
// @lc code=end
