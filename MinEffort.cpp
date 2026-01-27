#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        int ans =INT_MAX;
       int dx[4]={-1,0,1,0};
       int dy[4]={0,-1,0,1};
       priority_queue<
        pair<pair<int,int>, pair<int,int>>, // Value type
        vector<pair<pair<int,int>, pair<int,int>>>, // Container
        greater<pair<pair<int,int>, pair<int,int>>> // Comparator
    > q;
    vector<vector<int>>finalize(row,vector<int>(col,-1));
      vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
       int start = heights[0][0];
       dist[0][0]=0;
       q.push({{0,start},{0,0}});
       while(!q.empty()){
        int qdiff = q.top().first.first;
        int qwt = q.top().first.second;
        int qx = q.top().second.first;
        int qy = q.top().second.second;
        q.pop();
        if(qx==row-1&&qy==col-1&&finalize[qx][qy]==1) break;
        //     ans.push_back(dist[])
        // };
        if(finalize[qx][qy]==1) continue;
        finalize[qx][qy]=1;
        for(int i=0;i<4;i++){
            int nx = dx[i]+qx;
            int ny = dy[i]+qy;
            if(nx<0||nx>=row||ny<0||ny>=col) continue;
            int diff = abs(heights[nx][ny]-heights[qx][qy]);
            int ndiff = max(qdiff,diff);
            if(dist[nx][ny]>ndiff){
                dist[nx][ny]=ndiff;
                q.push({{dist[nx][ny],heights[nx][ny]},{nx,ny}});
            }
        }
       }
       return dist[row-1][col-1];
    }
};
int main() {
    Solution s;

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    int result = s.minimumEffortPath(heights);

    cout << "Minimum Effort Path: " << result << endl;

    return 0;
}