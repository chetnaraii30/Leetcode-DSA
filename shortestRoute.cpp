#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<vector<int>>edges(b,vector<int>(3));
    vector<vector<int>>queries(c,vector<int>(2));
    for(int i=0;i<b;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    for(int i=0;i<c;i++){
        cin>>queries[i][0]>>queries[i][1];
    }
    for(int i=0;i<c;i++){
        int src = queries[i][0];
        int dest = queries[i][1];
        vector<long long >dist(a+1,LLONG_MAX);
        dist[src]=0;
        for(int j=1;j<a;j++){
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u]==LLONG_MAX) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
            if(dist[v]==LLONG_MAX) continue;
            if(dist[u]>dist[v]+w){
                dist[u]=dist[v]+w;
            }
        }
    }
    if(dist[dest]==LLONG_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[dest]<<endl;
    }
    }
}       