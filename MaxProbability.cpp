#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    //    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>q;
    priority_queue<pair<double,int>>q;
       vector<vector<pair<int,double>>>AdjList(n);
        vector<double>dist(n,0.0);
        vector<int>finalize(n,-1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            AdjList[u].push_back({v,w});
            AdjList[v].push_back({u,w});
        }
        dist[start_node] = 1.0;
        q.push({dist[start_node],start_node});
        while(!q.empty()){
            double qw = q.top().first;
            int qn = q.top().second;
            q.pop();
            if(finalize[qn]==1) continue;
            finalize[qn]=1;
            for(auto e:AdjList[qn]){
                int node = e.first;
                double wt = e.second;
                    if(dist[node]<dist[qn]*wt){
                        dist[node] = dist[qn]*wt;
                        q.push({dist[node],node});
                    }
                    
            }

        }
        return dist[end_node];
    }
};
int main() {
    Solution s;

    int n = 3;
    vector<vector<int>> edges = {{0,1}, {1,2}, {0,2}};
    vector<double> succProb = {0.5, 0.5, 0.2};

    int start = 0, end = 2;

    double result = s.maxProbability(n, edges, succProb, start, end);

    cout << "Maximum Probability Path: " << result << endl;

    return 0;
}