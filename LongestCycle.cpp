#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
void bfs(vector<int>&visited,vector<int>&Indegree,vector<vector<int>>&AdjList){
    queue<int>q;
    for(int i=0;i<Indegree.size();i++){
        if(Indegree[i]==0){
            q.push(i);
            visited[i]=1;
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &e:AdjList[node]){
            Indegree[e]--;
            if(Indegree[e]==0){
                q.push(e);
                visited[e]=1;
            }
        }
    }
}
void dfs(int start,vector<int>&visited,vector<vector<int>>&AdjList,int &count){
    visited[start]=1;
    for(auto &e:AdjList[start]){
        if(visited[e]==-1){
            count++;
            dfs(e,visited,AdjList,count);
        }
    }
}
    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        int count=1;
        int ans=INT_MIN;
       vector<vector<int>>AdjList(V);
       vector<int>visited(V,-1);
       vector<int>Indegree(V);
       for(int i=0;i<V;i++){
        int v=edges[i];
        if(v!=-1){
            AdjList[i].push_back(v);
        Indegree[v]++;
        }
       } 
        bfs(visited,Indegree,AdjList);
        for(int i=0;i<V;i++){
            if(visited[i]==-1){
                dfs(i,visited,AdjList,count);
                ans = max(count,ans);
                count=1;
            }
        }
        return (ans==INT_MIN?-1:ans);
    }
};
int main() {
    Solution sol;

    // Example edges: graph with a cycle of length 3 (0 -> 1 -> 2 -> 0)
    vector<int> edges = {1, 2, 0, 4, 5, 3};

    int result = sol.longestCycle(edges);
    cout << "Length of the longest cycle: " << result << endl;

    return 0;
}