/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */
#include "head.h"
// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        int length = bank.size();
        int ans = 0;

        queue<string> que;
        unordered_set<string> st;
        que.push(start);
        st.insert(start);

        while (que.size() > 0) {
            string s = que.back();
            que.pop();

            ans++;
            for (size_t i = 0; i < length; i++) {
                string s_next = bank[i];
                if (st.count(s_next) > 0) {
                    continue;
                }

                int match_num = 0;
                for (size_t j = 0; j < 8; j++) {
                    match_num += static_cast<int>(s[j] != s_next[j]);
                }

                if (match_num == 1) {
                    if (s_next == end)
                        return ans;

                    que.push(s_next);
                    st.insert(s_next);
                }
            }
        }

        return -1;
    }
};
// @lc code=end
