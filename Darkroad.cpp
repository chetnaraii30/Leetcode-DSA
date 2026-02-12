#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <functional>

using namespace std;
int main(){
    while(true){
    int n,m;
    cin>>n>>m;
    if(n==0 && m==0) break;
    vector<vector<int>>road(m,vector<int>(3));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<vector<pair<int,int>>>AdjList(n);
    vector<int>visited(n,-1);
    int total=0;
    for(int i=0;i<m;i++){
        cin>>road[i][0]>>road[i][1]>>road[i][2];
        total += road[i][2];
        AdjList[road[i][0]].push_back({road[i][1],road[i][2]});
        AdjList[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    q.push({0,0});
    int cost=0;
    while(!q.empty()){
        int dis = q.top().first;
        int node = q.top().second;
        q.pop();
        if(visited[node]==1) continue;
        visited[node]=1;
        cost += dis;
        for(auto e:AdjList[node]){
            int nod = e.first;
            int cst = e.second;
            if(visited[nod]==-1){
            q.push({cst,nod});
            }
        }
    }
    int ans = total - cost;
    cout<<ans<<endl;
}
}