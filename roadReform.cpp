#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>>road(m,vector<int>(3));
        vector<vector<pair<int,int>>>AdjList(n+1);
        vector<int>visited(n+1,-1);
        vector<int>str;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        for(int i=0;i<m;i++){
            cin>>road[i][0]>>road[i][1]>>road[i][2];
            str.push_back(road[i][2]);
            AdjList[road[i][0]].push_back({road[i][1],road[i][2]});
            AdjList[road[i][1]].push_back({road[i][0],road[i][2]});
        }
        q.push({0,1});
        long long cost=0;
        long long count=0;
        while(!q.empty()){
            long long dis = q.top().first;
            int node = q.top().second;
            q.pop();
            if(visited[node]==1) continue;
            visited[node]=1;
            if(dis>k){
                int diff = dis-k;
                count += diff;
            }
            cost += dis;
            for(auto e:AdjList[node]){
                int nod = e.first;
                long long cst = e.second;
                if(visited[nod]==1)continue;
                q.push({cst,nod});
            }
        }
        if(count==0){
            long long ans = LONG_MAX;
            for(int x:str){
                ans = min(ans,llabs(x-k));
            }
            cout<<ans<<endl;
        }
        else{
            cout<<count<<endl;
        }
    }
    return 0;
}