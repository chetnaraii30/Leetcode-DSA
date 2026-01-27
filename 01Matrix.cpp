#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>direction{{0,1},{0,-1},{1,0},{-1,0}};
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>que;
        vector<vector<int>>result(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()){
            pair<int,int>p = que.front();
            que.pop();
            int i = p.first;
            int j = p.second;
            for(auto &dir:direction){
                int newi = i + dir[0];
                int newj = j + dir[1];
            if(newi >= 0 && newi < m && newj >= 0 && newj < n && result[newi][newj]==-1){
                que.push({newi,newj});
                result[newi][newj] = result[i][j] + 1;
            }
        }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    
    vector<vector<int>> ans = sol.updateMatrix(mat);
    
    cout << "Updated Matrix:\n";
    for(auto &row : ans){
        for(auto &x : row) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}