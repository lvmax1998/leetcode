/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxcnt(answerKey, 'T', k), maxcnt(answerKey, 'F', k));
    }

    int maxcnt(const string &answerKey, const char &c, const int &k) {
        int sum = 0;
        int ans = 0;

        for (int left = 0, right = 0; right < answerKey.length(); right++) {

            sum += answerKey[right] != c;
            while (sum > k) {
                sum -= answerKey[left++] != c;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
// @lc code=end
