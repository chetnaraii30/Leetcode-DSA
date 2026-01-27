#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>AdjList(n);
        vector<bool>visited(n,false);
        queue<int>q;
        for(auto &e:edges){
            int u= e[0];
            int v= e[1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        if(source==destination) return true;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int x:AdjList[node]){
                if(x==destination) return true;
                else if( visited[x]==false){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << s.validPath(3, edges, 0, 2);
    return 0;
}