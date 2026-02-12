#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>AdjList(n+1);
    vector<vector<int>>road(m,vector<int>(3));
    vector<int>visited(n+1,-1);
    vector<int>parent(n+1,-1);
    priority_queue<pair<long long, pair<int,int>>,vector<pair<long long, pair<int,int>>>,greater<pair<long long, pair<int,int>>>>q;
    vector<long long>dist(n+1,0);
    for(int i=0;i<m;i++){
        cin>>road[i][0]>>road[i][1]>>road[i][2];
        AdjList[road[i][0]].push_back({road[i][1],road[i][2]});
        AdjList[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    dist[1] = 0;
    long long cost = 0;
    q.push({0,{1,-1}});;
    while(!q.empty()){
        int wt = q.top().first;
        int node = q.top().second.first;
        int par = q.top().second.second;
        q.pop();
        if(visited[node]==1) continue;
        visited[node]=1;
        for(auto e:AdjList[node]){
            int nod = e.first;
            int cst =  e.second;
            if(visited[nod]==-1){
                dist[nod] = cst;
            cost += e.second;
            q.push({dist[nod],{nod,node}});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==-1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<cost<<endl;
}
   