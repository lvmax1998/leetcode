/*
 * @lc app=leetcode.cn id=2022 lang=cpp
 *
 * [2022] 将一维数组转变成二维数组
 */

#include "head.h"

// @lc code=start
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (m * n != original.size())
        {
            return vector<vector<int>>();
        }

        int count = 0;
        vector<vector<int>> result;
        for (size_t i = 0; i < m; i++)
        {
            vector<int> row;
            for (size_t j = 0; j < n; j++)
            {
                row.emplace_back(original[count]);
                count++;
            }

            result.emplace_back(row);
        }

        return result;
    }
};
// @lc code=end
