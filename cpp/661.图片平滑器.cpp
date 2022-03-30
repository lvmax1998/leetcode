/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        int m = img.size(), n = img[0].size();
        vector<int> filter(9);
        int cnt = 0;
        vector<vector<int>> ans(m, img[0]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (i + k < 0 || i + k >= m)
                        continue;
                    for (int l = -1; l <= 1; l++) {
                        if (j + l < 0 || j + l >= n)
                            continue;
                        filter[cnt] = img[i + k][j + l];
                        cnt++;
                    }
                }
                ans[i][j] = accumulate(filter.begin(), filter.begin() + cnt, 0) / cnt;
                cnt = 0;
            }
        }

        return ans;
    }
};
// @lc code=end
