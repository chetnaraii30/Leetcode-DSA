#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool bfs(int start,int parent,vector<int>&visited,vector<vector<int>>&AdjList){
   queue<pair<int,int>>q;
    q.push({start,parent});
    visited[start]=1;
    bool isCycle = true;
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        if(AdjList[node].size()!=2){
             isCycle = false;
            // return false;
        }
        for(int e:AdjList[node]){
            if(e==par) continue;
            if(visited[e]==-1){
                visited[e]=1;
                q.push({e,node});
            }
        }
    }
     return isCycle;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>AdjList(n+1);
    vector<int>visited(n+1,-1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u;
        cin>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    int component=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==-1){
            if(bfs(i,-1,visited,AdjList)){
                component++;
            }
        }
    }
    cout<<component<<endl;
}