#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    void bfs(int i,vector<vector<int>>& isConnected,vector<int>&visited){
        queue<int>q;
        int n = isConnected.size();
        q.push(i);
        visited[i]= 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(isConnected[node][j]==1 && visited[j]==-1){
                    q.push(j);
                    visited[j]=0;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,-1);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                bfs(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};
int main() {
    Solution s;
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << s.findCircleNum(isConnected);
    return 0;
}