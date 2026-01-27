#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
void bfs(int i,int j,vector<vector<int>>&grid){
    queue<pair<int,int>>q;
    int row = grid.size();
    int col = grid[0].size();
    q.push({i,j});
    grid[i][j]=0;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    while(!q.empty()){
        int cox = q.front().first;
        int coy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = dx[i]+cox;
            int ny = dy[i]+coy;
            if(nx<0||nx>=row||ny<0||ny>=col||grid[nx][ny]!=1) continue;
            if(grid[nx][ny]==1){
               q.push({nx,ny});
               grid[nx][ny]=0;
            }
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count=0;
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==0||i==row-1||j==0||j==col-1){
                if(grid[i][j]==1){
                    bfs(i,j,grid);
                }
            }
        }
       }
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                count++;
            }
        }
       }
       return count;
    }
};
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int result = sol.numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl;

    return 0;
}