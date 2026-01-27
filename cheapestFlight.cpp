#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>AdjList(n);
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
         vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
         dist[src][0] = 0;
        int stop=0;
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            AdjList[u].push_back({v,w});
        }
        q.push({0,{src,stop}});
        while(!q.empty()){
            int dis = q.top().first;
            int node = q.top().second.first;
            int stop = q.top().second.second;
            q.pop();
            //  if(dis > dist[node]) continue;
            if(node == dst) return dis;
            if(stop > k) continue;
            for(auto e:AdjList[node]){
                int nd = e.first;
                int w = e.second;
                    if(dist[nd][stop+1]>w+dis){
                    dist[nd][stop+1]= w+dis;
                    q.push({dist[nd][stop+1],{nd,stop+1}});
                    }
            }
        }
        return -1;
    }
};
int main() {
    Solution s;

    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,3,100},{0,2,500}};
    int src = 0, dst = 3, k = 1;

    int result = s.findCheapestPrice(n, flights, src, dst, k);

    if(result == -1)
        cout << "No route within " << k << " stops." << endl;
    else
        cout << "Cheapest price: " << result << endl;

    return 0;
}