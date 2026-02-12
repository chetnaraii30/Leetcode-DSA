#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int start,int parent,vector<int>&visited,vector<vector<pair<int,int>>>&AdjList,int &count){
    visited[start] = 1;
    for(auto e:AdjList[start]){
        int nod = e.first;
        int cost = e.second;
        if(nod==parent) continue;
        if(visited[nod]==-1){
            count += cost;
            dfs(nod,start,visited,AdjList,count);
        }
        // else{
        //     count -= cost;
        //     return;
        // }
    }
    // visited[start]=-1;
}
int main(){
    int n;
    cin>>n;
    int a,b,c;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<pair<int,int>>>AdjList(n+1);
    vector<int>visited(n+1,-1);
    for(int i=0;i<arr.size();i++){
        int u = arr[i][0];
        int v = arr[i][1];
        int w = arr[i][2];
        AdjList[u].push_back({v,0});
        AdjList[v].push_back({u,w});
    }
    vector<int>ans;
    // int count = 0; 
    for(int i=1;i<=n;i++){
         int count = 0; 
        if(visited[i]==-1){
            dfs(i,-1,visited,AdjList,count);
                ans.push_back(count);
            // count=0;
        }
    }
    int min = *min_element(ans.begin(),ans.end());
    cout<<min<<endl;
}