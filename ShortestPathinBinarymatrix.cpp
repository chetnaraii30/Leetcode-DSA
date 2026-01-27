#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>q;
        int dx[8]={-1,0,1,0,-1,-1,1,1};
        int dy[8]={0,-1,0,1,-1,1,1,-1};
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
        vector<vector<int>>finalize(row,vector<int>(col,-1));
        if(grid[0][0]==1) return -1;
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis = q.top().first;
            int cox = q.top().second.first;
            int coy = q.top().second.second;
            q.pop();
            if(finalize[cox][coy]==1) continue;
            finalize[cox][coy]=1;
            for(int i=0;i<8;i++){
                int nx = dx[i]+cox;
                int ny = dy[i]+coy;
                if(nx>=row||ny>=col||nx<0||ny<0||grid[nx][ny]==1) continue;
                if(dist[nx][ny]>dis+1){
                    dist[nx][ny]=dis+1;
                    q.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        if(dist[row-1][col-1]==INT_MAX){
            return -1;
        }
        return dist[row-1][col-1];
    }
};
int main() {
    Solution s;

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    int result = s.shortestPathBinaryMatrix(grid);

    if(result == -1)
        cout << "No path exists." << endl;
    else
        cout << "Shortest path length: " << result << endl;

    return 0;
}