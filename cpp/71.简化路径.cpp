/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include "head.h"
// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;

        int start, end;
        start = path.find('/');
        while (start != string::npos && start != path.size() - 1)
        {
            end = path.find('/', start + 1);

            string s = path.substr(start + 1, end - start - 1);
            // cout << s << endl;

            if (s.length() && s.compare(".") != 0)
            {
                if (s.compare("..") == 0)
                {
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push(s);
                }
            }

            start = end;
        }

        if (st.empty())
        {
            return "/";
        }

        string re = st.top();
        st.pop();
        while (!st.empty())
        {
            re = st.top() + "/" + re;
            // cout << st.top() << endl;
            st.pop();
        }

        return "/" + re;
    }
};
// @lc code=end
