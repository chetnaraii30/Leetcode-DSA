#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(3));
    vector<vector<pair<int,int>>>AdjList(n+1);
    vector<long long>dist(n+1,LLONG_MAX);
    vector<int>visited(n+1,-1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
        AdjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    dist[1] =0;
    q.push({0,1});
    while(!q.empty()){
        int dis = q.top().first;
        int node = q.top().second;
        q.pop();
        if(visited[node]==1) continue;
        visited[node]=1;
        for(auto e:AdjList[node]){
            int nod = e.first;
            int wt = e.second;
            if(dist[nod]>dist[node]+wt){
                dist[nod] = dist[node]+wt;
                q.push({dist[nod],nod});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}