#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n);
        vector<set<int>>as(n);
        vector<vector<int>>AdjList(n);
        vector<int>Indegree(n);
        queue<int>q;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            AdjList[u].push_back(v);
            Indegree[v]++;
        }
        for(int i=0;i<Indegree.size();i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int e:AdjList[node]){
                as[e].insert(node);
                for(int ed:as[node]){
                as[e].insert(ed);
                }
                Indegree[e]--;
                if(Indegree[e]==0){
                    q.push(e);
                }
            }
        }
        for (int i = 0; i < n; i++) {
        for (int x : as[i]) {
        ans[i].push_back(x);
    }
}

        return ans;
    }
};
int main() {
    Solution s;

    int n = 8;
    vector<vector<int>> edges = {
        {0,3},{0,4},{1,3},{2,4},{2,7},
        {3,5},{3,6},{3,7},{4,6}
    };

    vector<vector<int>> result = s.getAncestors(n, edges);

    cout << "Ancestors for each node:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": ";
        for (int x : result[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}