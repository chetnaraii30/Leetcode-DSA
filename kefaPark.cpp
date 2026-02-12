#include<iostream>
#include<vector>
using namespace std;
void dfs(int start,vector<int>&visited,vector<int>&leaf,vector<vector<int>>&AdjList,vector<int>&cat,int m,int count,int &ans){
    if(cat[start]==1){
        count++;
    }
    else{
        count =0;
    }
    if(count>m) return;
    visited[start]=1;
    bool isLeaf = true;
    for(int e:AdjList[start]){
        if(visited[e]==1) continue;
        isLeaf = false;
        dfs(e,visited,leaf,AdjList,cat,m,count,ans);
    }
    if(isLeaf){
        ans++;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>AdjList(n+1);
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    vector<int>leaf(n+1,0);
    for(int i=2;i<=n;i++){
        if(AdjList[i].size()==1){
            leaf[i] = 1;
        }
    }
    vector<int>cat(n+1,0);
    vector<int>visited(n+1,-1);
    int count=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==1){
            cat[i] = 1;
        }
    }
    dfs(1,visited,leaf,AdjList,cat,m,count,ans);
    cout<<ans<<endl;
}