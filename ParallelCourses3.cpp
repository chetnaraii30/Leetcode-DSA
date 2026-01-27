#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>AdjList(n+1);
        vector<int>Indegree(n+1);
        vector<int>mnt(n+1,0);
        queue<int>q;
        for(int i=0;i<relations.size();i++){
            int u = relations[i][0];
            int v = relations[i][1];
            AdjList[u].push_back(v);
            Indegree[v]++;
        }
        for(int i=1;i<=n;i++){
            if(Indegree[i]==0){
                q.push(i);
                mnt[i] = time[i-1];
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &e:AdjList[node]){
                mnt[e] = max(mnt[e],mnt[node]+time[e-1]);
                Indegree[e]--;
                if(Indegree[e]==0){
                    q.push(e);
                }
            }
        }
        return *max_element(mnt.begin(),mnt.end());
    }
};

int main() {
    Solution sol;

    int n = 5;
    vector<vector<int>> relations = {
        {1,2},
        {1,3},
        {3,4},
        {2,4},
        {4,5}
    };
    vector<int> time = {1,2,3,4,5};

    int result = sol.minimumTime(n, relations, time);
    cout << "Minimum time to complete all courses: " << result << endl;

    return 0;
}