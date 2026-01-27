#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
void dfs(int i,vector<int>&Indegree,vector<vector<int>>&AdjList,vector<vector<int>>&graph,vector<int>&ans){
    ans.push_back(i);
    for(int e:AdjList[i]){
        Indegree[e]--;
        if(Indegree[e]==0){
            dfs(e,Indegree,AdjList,graph,ans);
        }
    }
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
       vector<vector<int>>AdjList(V);
       vector<int>Indegree(V);
       queue<int>q;
       vector<int>ans;
       for(int u=0;u<V;u++){
        for(int v:graph[u]){
            AdjList[v].push_back(u);
            Indegree[u]++;
        }
       }
       for(int i=0;i<V;i++){
        if(Indegree[i]==0){
            // q.push(i);
            dfs(i,Indegree,AdjList,graph,ans);
        }
       }
    //    while(!q.empty()){
    //     int node = q.front();
    //     ans.push_back(node);
    //     q.pop();
    //     for(int e:AdjList[node]){
    //         Indegree[e]--;
    //         if(Indegree[e]==0){
    //             q.push(e);
    //         }
    //     }
    //    }
       sort(ans.begin(),ans.end());
       return ans;
    }
};
int main() {
    Solution s;

    vector<vector<int>> graph = {
        {1, 2},   // 0 -> 1, 2
        {2, 3},   // 1 -> 2, 3
        {5},      // 2 -> 5
        {0},      // 3 -> 0
        {5},      // 4 -> 5
        {},       // 5 -> terminal
        {}        // 6 -> terminal
    };

    vector<int> safeNodes = s.eventualSafeNodes(graph);

    cout << "Eventual Safe Nodes: ";
    for(int x : safeNodes) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}