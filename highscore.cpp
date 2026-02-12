#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>dist(n+1,LLONG_MIN);
    vector<vector<int>>edges(m,vector<int>(3));
    queue<int> q;
    vector<int> visited(n+1, 0);
    vector<vector<int>>AdjList(n+1);
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
        AdjList[edges[i][0]].push_back(edges[i][1]);
    }
    dist[1]=0;
    for(int i=1;i<n;i++){
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u]==LLONG_MIN) continue;
            if(dist[v]<dist[u]+w){
               dist[v] = dist[u]+w;
            }
        }
    }
    vector<int>bad(n+1,0);
    for(auto &e:edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(dist[u]==LLONG_MIN) continue;
        if(dist[v]<dist[u]+w){
            bad[v] = 1;
            q.push(v);
            visited[v]=1;
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node==n){
            cout<<-1<<endl;
            return 0;
        }
        for(int e:AdjList[node]){
            if(!visited[e]){
                visited[e]=1;
                q.push(e);
            }
        }
    }
    cout<<dist[n]<<endl;
}