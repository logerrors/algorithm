#include <leetcode.hpp>

using namespace leetcode;

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> inDegree(numCourses, 0);

        std::unordered_map<int, std::vector<int>> graph;
        for(int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        std::deque<int> q;
        for(int i = 0; i < inDegree.size(); ++i) {
            if(inDegree[i] == 0) {
                q.push_back(i);
            }
        }

        int count = 0;
        while(!q.empty()) {
            auto selected = q.front();
            q.pop_front();
            count++;
            auto& toEnQueue = graph[selected];
            for(auto ele : toEnQueue){
                inDegree[ele]--;
                if(inDegree[ele] == 0){
                    q.push_back(ele);
                }
            }
        }

        return count == numCourses;
    }
};