#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>AdjList(n+1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long,int>>>q;
    vector<long long>dist(n+1,LLONG_MAX);
    vector<int>parent(n+1,-1);
    vector<int>finalize(n+1,-1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        AdjList[u].push_back({v,w});
        AdjList[v].push_back({u,w});
    }
    dist[1]=0;
    q.push({0,1});
    while(!q.empty()){
        int dis = q.top().first;
        int node = q.top().second;
        q.pop();
        if(finalize[node]==1) continue;
        finalize[node] = 1;
        if(dis > dist[node]) continue;
        for(auto &e:AdjList[node]){
            int nod = e.first;
            int wt = e.second;
            if(dist[nod]>dist[node]+wt){
                parent[nod] = node;
                dist[nod] = dist[node]+wt;
                q.push({dist[nod],nod});
            }
        }
    }
    if(dist[n] == LLONG_MAX){
        cout << -1 << endl; 
        return 0;
    }
    vector<int>path;
    int curr = n;
    while(curr!=-1){
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(),path.end());
    for(int x:path){
        cout<<x<<" ";
    }
}
