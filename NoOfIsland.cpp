
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
int n;
int m;
void dfs(vector<vector<char>>& grid,int i,int j){
    if(i<0||i>=n||j<0||j>=m||grid[i][j]!= '1'){
        return;
    }
    if(grid[i][j]=='$'){
        return;
    }
    grid[i][j] ='$';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}
    int numIslands(vector<vector<char>>& grid) {
       n=grid.size();
       m=grid[0].size();
       int island =0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j);
                island++;
            }
        }
       }
       return island; 
    }
};
int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << sol.numIslands(grid) << endl;
    return 0;
}