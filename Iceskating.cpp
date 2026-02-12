#include<iostream>
#include<vector>
using namespace std;
void dfs(int i,vector<int>&visited,vector<vector<int>>&adjList){
    visited[i]=1;
    for(int e:adjList[i]){
        if(visited[e]==1) continue;
        dfs(e,visited,adjList);
    }
}
int main(){
   int n;
   cin>>n;
   vector<pair<int,int>>maxx(n+1);
   for(int i=1;i<=n;i++){
    cin>>maxx[i].first>>maxx[i].second;
   }
   vector<vector<int>>adjList(n+1);
   vector<int>visited(n+1,-1);
   for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
        if(maxx[i].first == maxx[j].first || maxx[i].second == maxx[j].second){
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
    }
   }
   int component=0;
   for(int i=1;i<=n;i++){
    if(visited[i]==-1){
        dfs(i,visited,adjList);
        component++;
    }
   }
   cout<<component-1<<endl;
}