#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
void bfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dist){
    queue<pair<pair<int,int>,int>>q;
    dist[i][j]=0;
    q.push({{i,j},0});
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
     int row = grid.size();
     int col = grid[0].size();
    while(!q.empty()){
         int dis = q.front().second;
         int cox = q.front().first.first;
         int coy = q.front().first.second;
         q.pop();
         for(int i=0;i<4;i++){
            int nx = dx[i]+cox;
            int ny = dy[i]+coy;
            if(nx<0||nx>=row||ny<0||ny>=col||grid[nx][ny]==1) continue;
            int mdist = abs(nx-cox)+abs(ny-coy);
            if(dist[nx][ny]>dis+mdist){
                dist[nx][ny] = dis+mdist;
                q.push({{nx,ny},dist[nx][ny]});
            }
         }
    }
}
    int maxDistance(vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid[0].size();
       int ans=0;
       vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                bfs(i,j,grid,dist);
            }
        }
       } 
       if(dist[0][0]==INT_MAX) return -1;
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ans = max(ans,dist[i][j]);
        }
       }
       if(ans==0) return -1;
       return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    cout << sol.maxDistance(grid) << endl;  // Output: 2
    return 0;
}