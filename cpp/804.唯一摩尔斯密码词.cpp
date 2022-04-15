/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */
#include "head.h"
// @lc code=start
class Solution {
private:
    vector<string> table = {".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
                            ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

public:
    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> s;
        for (auto &&word : words) {
            string temp("");
            for (auto &&c : word) {
                temp += table[c - 'a'];
            }
            s.emplace(move(temp));
        }

        return s.size();
    }
};
// @lc code=end
