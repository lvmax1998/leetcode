/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
                vector<int> max_row, max_col;

        int count = grid[0].size();
        for (size_t i = 0; i < count; i++)
        {
            int max_row_idx = 0, max_col_idx = 0;
            for (size_t j = 1; j < count; j++)
            {
                if (grid[i][j] > grid[i][max_col_idx])
                    max_col_idx = j;
                if (grid[j][i] > grid[max_row_idx][i])
                    max_row_idx = j;
            }
            
            max_row.push_back(grid[max_row_idx][i]);
            max_col.push_back(grid[i][max_col_idx]);
        }


        int sum = 0;
        for (size_t i = 0; i < count; i++)
        {
            for (size_t j = 0; j < count; j++)
            {
                sum += min(max_row[i], max_col[j]) - grid[j][i];
            }
            
        }

        return sum;
    }
};
// @lc code=end

