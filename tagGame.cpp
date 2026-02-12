#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int start,vector<vector<int>>&AdjList,vector<int>&dist){
    queue<int>q;
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next:AdjList[node]){
            if(dist[next]==-1){
                dist[next]=dist[node]+1;
                q.push(next);
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>AdjList(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    vector<int>distA(n+1,-1);
    vector<int>distB(n+1,-1);
    bfs(1,AdjList,distA);
    bfs(m,AdjList,distB);
    int best=0;
    for(int i=1;i<=n;i++){
        if(AdjList[i].size()==1&&i!=1){
            if(distB[i]<distA[i]){
                best = max(best,distA[i]);
            }
        }
    }
    cout<<2*best<<endl;
}