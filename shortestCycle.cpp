#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
bool bfs(int start,int parent,vector<int>&visited,vector<vector<int>>&AdjList,int &ans){
    queue<pair<int,int>>q;
    vector<int> dist(visited.size(), -1);
    q.push({start,parent});
    dist[start] = 0;
    visited[start]=1;
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto &e:AdjList[node]){
            if(visited[e]==-1){
                q.push({e,node});
                visited[e]=1;
                dist[e] = dist[node] + 1;
            }
            else if(e!=par){
                int currLen = dist[node]+dist[e]+1;
                ans = min(ans,currLen);
            }
        }
    }
    return false;
}
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>AdjList(n);
        int ans = INT_MAX;
        int count = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            vector<int>visited(n,-1);
            bfs(i,-1,visited,AdjList,ans);
        }
        return (ans==INT_MAX?-1:ans);
    }
}; 
int main() {
    Solution sol;

    int n = 5; // number of nodes
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,0},
        {1,3},
        {3,4}
    };

    int result = sol.findShortestCycle(n, edges);
    cout << "Length of the shortest cycle: " << result << endl;

    return 0;
}