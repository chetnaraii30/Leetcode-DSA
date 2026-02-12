#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int i=1;
    if(n>=m){
        int time = n-m;
        cout<<time<<endl;
        return 0;
    }
    int maxi = m*2;
    vector<vector<int>>Adjlist(maxi+1);
    vector<int>visited(maxi+1,-1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int>dist(maxi+1,INT_MAX);
    for(int i=1;i<=maxi;i++){
        if(i==1){
            Adjlist[i].push_back(i*2);
        }
        else if(i*2>maxi){
            Adjlist[i].push_back(i-1);
        }
        else{
            Adjlist[i].push_back(i-1);
            Adjlist[i].push_back(i*2);
        }
    }
    dist[n]=0;
    q.push({0,n});
    while(!q.empty()){
        int node = q.top().second;
        int dis = q.top().first;
        q.pop();
        if(visited[node]==1) continue;
        visited[node]=1;
        for(int e:Adjlist[node]){
            if(dist[e]>dist[node]+1){
                dist[e]=dist[node]+1;
                q.push({dist[e],e});
            }
        }
    }
    cout<<dist[m]<<endl;
    return 0;
}