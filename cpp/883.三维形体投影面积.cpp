/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int max_x = 0, max_y = 0, max_z = 0;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            int y = 0, x = 0;
            for (int j = 0; j < n; j++) {
                max_z += grid[i][j] > 0 ? 1 : 0;
                y = max(y, grid[i][j]);
                x = max(x, grid[j][i]);
            }

            max_y += y;
            max_x += x;
        }

        return max_x + max_y + max_z;
    }
};
// @lc code=end
