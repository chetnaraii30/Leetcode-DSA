#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
       int freshCount =0;
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1){
                freshCount++;
            }
        }
       }
       if(freshCount==0){
        return 0;
       }
       int minutes=0;
       while(!q.empty()){
        int no = q.size();
        while(no--){
            pair<int,int>curr  = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            for( auto &dir:directions){
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]==1){
                    grid[new_i][new_j]=2;
                    q.push({new_i,new_j});
                    freshCount--;
                }
            }
        }
        minutes++;
       }
       return freshCount==0? (minutes-1):-1;
    }
};
int main() {
    Solution s;

    // Sample test case
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = s.orangesRotting(grid);
    cout << "Minutes to rot all oranges: " << result << endl;

    return 0;
}