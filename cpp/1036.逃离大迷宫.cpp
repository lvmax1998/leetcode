/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */
#include "head.h"
// @lc code=start
class Solution
{
private:
    struct KeyHash
    {
        std::size_t operator()(const vector<int> &k) const
        {
            string s = to_string(k[0]) + "-" + to_string(k[1]);
            return hash<string>()(s);
        }
    };

    struct KeyEqual
    {
        bool operator()(const vector<int> &lhs, const vector<int> &rhs) const
        {
            return lhs[0] == rhs[0] && lhs[1] == rhs[1];
        }
    };

public:
    using Set = unordered_set<vector<int>, KeyHash, KeyEqual>;
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
        Set m;

        for (const auto &x : blocked)
            m.insert(x);

        return bfs(source, target, m) && bfs(target, source, m);
    }

    bool bfs(vector<int> &source, vector<int> &target, Set m)
    {
        queue<vector<int>> q;
        Set v;

        visit(source, q, m, v);

        while (!q.empty() && v.size() <= 1e5)
        {
            vector<int> point = q.front();
            q.pop();
            if (point == target)
                return true;
            visit(point, q, m, v);
        }

        return v.size() > 1e5;
    }

    void visit(const vector<int> &point, queue<vector<int>> &q, const Set &m, Set &v)
    {
        int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int x = point[0] + move[i][0];
            int y = point[1] + move[i][1];

            if (x < 10e6 && x >= 0 && y < 10e6 && y >= 0 && !m.count({x, y}) && !v.count({x, y}))
            {
                q.push({x, y});
                v.insert({x, y});
            }
        }
    }
};
// @lc code=end
