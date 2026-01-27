#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
void bfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&visited){
    queue<pair<int,int>>q;
     int row = board.size();
     int col = board[0].size();
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        int cox = q.front().first;
        int coy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = dx[i]+cox;
            int ny = dy[i]+coy;
            if(nx>=row||nx<0||ny>=col||ny<0) continue;
            if(visited[nx][ny]==-1&&board[nx][ny]=='O'){
                q.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
    }
}
    void solve(vector<vector<char>>& board) {
      int row = board.size();
      int col = board[0].size();
      vector<vector<int>>visited(row,vector<int>(col,-1));
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if((i==0||i==row-1||j==0||j==col-1)&&board[i][j]=='O'&&visited[i][j]==-1){
                bfs(i,j,board,visited);
            }
        }
      }
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]=='O'&&visited[i][j]==-1){
                board[i][j]='X';
                visited[i][j]=1;
            }
        }
      }
    }
};
int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    cout << "Original Board:\n";
    for(auto &row : board){
        for(auto &ch : row) cout << ch << " ";
        cout << endl;
    }

    sol.solve(board);

    cout << "\nBoard After Solve:\n";
    for(auto &row : board){
        for(auto &ch : row) cout << ch << " ";
        cout << endl;
    }

    return 0;
}