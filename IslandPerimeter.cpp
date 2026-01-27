#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    continue;
                }
                if(j==m-1||grid[i][j+1]==0){
                    perimeter++;
                }
                if(j==0||grid[i][j-1]==0){
                    perimeter++;
                }
                if(i==n-1||grid[i+1][j]==0){
                    perimeter++;
                }
                if(i==0||grid[i-1][j]==0){
                    perimeter++;
                }
            }
        }
        return perimeter;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,1,0,0},
                                {1,1,1,0},
                                {0,1,0,0},
                                {1,1,0,0}};
    cout << "Perimeter: " << sol.islandPerimeter(grid) << endl;
    return 0;
}