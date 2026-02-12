#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>AdjList(n+1);
vector<vector<int>>AdjList1(n+1);
vector<vector<int>>route(m,vector<int>(2));
vector<int>dist(n+1,INT_MAX);
vector<int>dist1(n+1,INT_MAX);
dist[1]=0;
dist1[1]=0;
vector<int>visited(n+1,-1);
vector<int>visitedT(n+1,-1);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
for(int i=0;i<m;i++){
    cin>>route[i][0]>>route[i][1];
    AdjList[route[i][0]].push_back(route[i][1]);
    AdjList[route[i][1]].push_back(route[i][0]);
}
for(int i=1;i<=n;i++){
  for(int j=i+1;j<=n;j++){
    if(i != j && 
   find(AdjList[i].begin(), AdjList[i].end(), j) == AdjList[i].end())
{
    AdjList1[i].push_back(j);
    AdjList1[j].push_back(i);
}
  }
}
q.push({0,1});
while(!q.empty()){
    int dis = q.top().first;
    int node = q.top().second;
    q.pop();
    if(visited[node]==1) continue;
    visited[node]=1;
    for(auto e:AdjList[node]){
        int nod = e;
        if(dist[nod]> dis+1){
            dist[nod] = dis+1;
            q.push({dist[nod],nod});
        }
    }
}
q.push({0,1});
while(!q.empty()){
    int dis = q.top().first;
    int node = q.top().second;
    q.pop();
    if(visitedT[node]==1) continue;
    visitedT[node]=1;
    for(int e:AdjList1[node]){
        int nod = e;
        if(dist1[nod]>dis+1){
            dist1[nod] = dis+1;
            q.push({dist1[nod],nod});
        }
    }
}
    if(dist[n] == INT_MAX || dist1[n] == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << max(dist[n], dist1[n]) << endl;
    }
}