#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({{i, j}, {-1, -1}});
        visited[i][j] = 1;

        int dirx[4] = {-1, 0, 1, 0};
        int diry[4] = {0, -1, 0, 1};

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int px = curr.second.first;
            int py = curr.second.second;

            for(int k = 0; k < 4; k++) {
                int nx = x + dirx[k];
                int ny = y + diry[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if(grid[nx][ny] != grid[x][y])
                    continue;

                if(visited[nx][ny] == -1) {
                    visited[nx][ny] = 1;
                    q.push({{nx, ny}, {x, y}});
                }
                else if(!(nx == px && ny == py)) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == -1) {
                    if(bfs(i, j, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    vector<vector<char>> grid = {
        {'a','a','a','a'},
        {'a','b','b','a'},
        {'a','b','b','a'},
        {'a','a','a','a'}
    };

    bool result = s.containsCycle(grid);

    if(result)
        cout << "Cycle detected in grid" << endl;
    else
        cout << "No cycle in grid" << endl;

    return 0;
}
