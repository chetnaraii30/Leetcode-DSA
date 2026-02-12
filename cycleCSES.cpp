#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(3));
    vector<long long>dist(n+1,0);
    vector<int>parent(n+1,-1);
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    for(int i=1;i<=n-1;i++){
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u]==LLONG_MAX) continue;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                parent[v] = u;
            }
        }
    }
    int cycle = -1;
    for(auto e:edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(dist[u]==LLONG_MAX) continue;
        if(dist[v]>dist[u]+w){
            parent[v]= u;
            cycle = v;
            break;
        }
    }
    if(cycle==-1){
        cout<<"NO"<<endl;
        return 0;
    }

    cout << "YES\n";
    for(int i=1;i<=n;i++){
        cycle = parent[cycle];
    }
    vector<int>path;
    int cur = cycle;
    path.push_back(cur);
    cur = parent[cur];
    while(cur!=cycle){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(cycle);
    reverse(path.begin(),path.end());
    for(int x:path){
        cout<<x<<" ";
    }
}