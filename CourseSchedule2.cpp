#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        int V = numCourses;
        vector<vector<int>>AdjList(V);
        vector<int>Indegree(V);
        queue<int>q;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            AdjList[u].push_back(v);
            Indegree[v]++;
        }
        for(int i=0;i<V;i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int e:AdjList[node]){
                Indegree[e]--;
                if(Indegree[e]==0){
                    q.push(e);
                }
            }
        }
        if(ans.size()==V){
            return ans;
        }
        ans.clear();
        return ans;
    }
};
int main() {
    Solution s;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> order = s.findOrder(numCourses, prerequisites);

    if(order.empty()) {
        cout << "No valid course order (cycle detected)" << endl;
    } else {
        cout << "Course Order: ";
        for(int x : order) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}