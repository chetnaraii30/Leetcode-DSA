#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
int n,m,k;
cin>>n>>m>>k;
vector<vector<int>>route(m,vector<int>(3));
vector<vector<pair<int,int>>>AdjList(n+1);
vector<long long>ans;
vector<int>visited(n+1,-1);
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
for(int i=0;i<m;i++){
cin>>route[i][0]>>route[i][1]>>route[i][2];
AdjList[route[i][0]].push_back({route[i][1],route[i][2]});
}
q.push({0,1});
while(!q.empty()){
    long long dis = q.top().first;
    int node = q.top().second;
    q.pop();
    if(visited[node]==k) continue;
    visited[node]++;
    if(node==n){
        ans.push_back(dis);
    }
    for(auto e:AdjList[node]){
        int nod = e.first;
        int wt = e.second;
        q.push({dis+wt,nod});
    }
}
for(int i=0;i<k;i++){
    cout<<ans[i]<<" ";
}
}