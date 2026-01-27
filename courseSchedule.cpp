#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int>ans;
        vector<vector<int>>AdjList(numCourses);
        vector<int>inDegree(V);
        queue<int>q;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            AdjList[u].push_back(v);
            inDegree[v]++;
        }
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int e:AdjList[node]){
                inDegree[e]--;
                if(inDegree[e]==0){
                    q.push(e);
                }
            }
        }
        return (ans.size()==numCourses) ;
    }
};
int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1,0},
        {2,1},
        {3,2}
    };

    bool result = sol.canFinish(numCourses, prerequisites);
    if(result)
        cout << "All courses can be finished." << endl;
    else
        cout << "Cannot finish all courses (cycle exists)." << endl;

    // Example with a cycle
    vector<vector<int>> prereq2 = {
        {1,0},
        {0,1}
    };
    bool res2 = sol.canFinish(2, prereq2);
    if(res2)
        cout << "All courses can be finished." << endl;
    else
        cout << "Cannot finish all courses (cycle exists)." << endl;

    return 0;
}