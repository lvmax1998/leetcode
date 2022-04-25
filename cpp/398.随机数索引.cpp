/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */
#include "head.h"
// @lc code=start
class Solution {
private:
    unordered_map<int, vector<int>> m_map;

public:
    Solution(vector<int> &nums) {

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (m_map.count(num)) {
                m_map[num].emplace_back(i);
            } else {
                m_map[num] = {i};
            }
        }
    }

    int pick(int target) {
        vector<int> v = m_map[target];
        int index = rand() % v.size();

        return v[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
