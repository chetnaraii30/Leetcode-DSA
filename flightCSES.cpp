#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>city(m,vector<int>(2));
    vector<vector<int>>AdjList(n+1);
    for(int i=0;i<m;i++){
        cin>>city[i][0]>>city[i][1];
        AdjList[city[i][0]].push_back(city[i][1]);
    }
    // for(int i=1;i<=n;i++){
        vector<int>visited(n+1,-1);
        queue<int>q;
        q.push(1);
        visited[1] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int e:AdjList[node]){
                if(visited[e]==1) continue;
                if(visited[e]==-1){
                    visited[e]=1;
                    q.push(e);
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(visited[j]==-1){
                cout<<"NO"<<endl;
                cout<<1<<" "<<j;
                return 0;
            }
        }
        vector<vector<int>>AdjList1(n+1);
        for(int i=0;i<m;i++){
            AdjList1[city[i][1]].push_back(city[i][0]);
        }
        vector<int>visited1(n+1,-1);
        q.push(1);
        visited1[1] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int e:AdjList1[node]){
                if(visited1[e]==1) continue;
                if(visited1[e]==-1){
                    visited1[e]=1;
                    q.push(e);
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(visited1[j]==-1){
                cout<<"NO"<<endl;
                cout<<j<<" "<<1;
                return 0;
            }
        }
    cout<<"YES"<<endl;
}