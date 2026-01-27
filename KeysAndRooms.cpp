#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
void bfs(int start,vector<int>&visited,vector<vector<int>>&AdjList,vector<vector<int>>&rooms){
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int e:AdjList[node]){
            if(visited[e]==-1){
                q.push(e);
                visited[e]=1;
            }
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
      vector<vector<int>>AdjList(n);
      vector<int>visited(n,-1);
      queue<int>q;
      int count=0;
      for(int i=0;i<rooms.size();i++){
       for(auto e:rooms[i]){
        int u=i;
        int v = e;
        AdjList[u].push_back(v);
       }
      }
      for(int i=0;i<rooms.size();i++){
        if(visited[i]==-1){
            bfs(i,visited,AdjList,rooms);
            count++;
        }
      }
      if(count==1){
        return true;
      }
      return false;
    }
};
int main() {
    Solution s;

    vector<vector<int>> rooms = {
        {1}, {2}, {3}, {}
    };

    bool result = s.canVisitAllRooms(rooms);

    if (result)
        cout << "All rooms can be visited." << endl;
    else
        cout << "Not all rooms can be visited." << endl;

    return 0;
}