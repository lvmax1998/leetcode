/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */
#include "head.h"
// @lc code=start

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int length = hand.size();
        if (length % groupSize != 0)
        {
            return false;
        }
        unordered_map<int, int> counter;
        sort(hand.begin(), hand.end());
        for_each(hand.begin(), hand.end(), [&counter](int x)
                 { counter[x]++; });

        for (const auto &item : hand)
        {
            if (counter.count(item) == 0)
            {
                continue;
            }

            for (size_t key = item; key < item + groupSize; key++)
            {
                if (counter.count(key) == 0)
                {
                    return false;
                }

                counter[key]--;
                if (counter[key] == 0)
                {
                    counter.erase(key);
                }
            }
        }

        return true;
    }
};
// @lc code=end
