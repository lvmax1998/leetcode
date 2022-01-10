/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

#include "head.h"

// @lc code=start
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> words;
        vector<string> result;

        int begin = 0, end = 0;
        while (end != -1)
        {
            end = text.find(' ', begin);
            words.push_back(text.substr(begin, end - begin));
            begin = end + 1;
        }

        for (size_t i = 2; i < words.size(); i++)
        {
            if (first.compare(words[i - 2]) == 0 && second.compare(words[i - 1]) == 0)
            {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
// @lc code=end
