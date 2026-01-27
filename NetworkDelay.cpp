#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=0;
        vector<vector<pair<int,int>>>AdjList(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>dist(n+1,INT_MAX);
        vector<int>finalize(n+1,-1);
        dist[k]=0;
        q.push({0,k});
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            AdjList[u].push_back({v,w});
        }
        while(!q.empty()){
            int qn = q.top().second;
            int qw = q.top().first;
            q.pop();
            if(finalize[qn]==1) continue;
            finalize[qn]=1;
            for(auto e:AdjList[qn]){
                int u = e.first;
                int v = e.second;
                if(dist[u]>v+dist[qn]){
                    dist[u]=v+dist[qn];
                    q.push({dist[u],u});
                }
                
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
int main() {
    Solution s;

    // Sample test case
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int n = 4;
    int k = 2;

    int result = s.networkDelayTime(times, n, k);

    if(result == -1)
        cout << "Not all nodes can be reached" << endl;
    else
        cout << "Network delay time: " << result << endl;

    return 0;
}