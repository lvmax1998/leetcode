/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include "head.h"

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {

            int length = q.size();
            vector<int> seq;
            for (int i = 0; i < length; i++) {
                auto visit = q.front();
                q.pop();
                seq.push_back(visit->val);
                for (auto &&child : visit->children) {
                    q.push(child);
                }
            }

            ans.emplace_back(seq);
        }

        return ans;
    }
};
// @lc code=end
