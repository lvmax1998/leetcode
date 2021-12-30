/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b)
        {
            return a[1] < b[1];
        });

        priority_queue<int> q;
        int sum = 0;
        int result = 0;

        for (const auto &course : courses)
        {   
            int duration = course[0];
            if (duration > course[1])
                continue;
            
            if (sum + duration <= course[1]){
                q.push(duration);
                sum += duration;
                result++;
            }else{
                if (q.size() == 0)
                    continue;
                int max_item = q.top();
                if (max_item > duration){
                    q.pop();
                    sum -= max_item;
                    q.push(duration);
                    sum += duration;
                }
            }
            
        }
        
        
        return result;
    }
};
// @lc code=end

