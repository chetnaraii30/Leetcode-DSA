#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes){ 
    vector<vector<int>>AdjList(n+1);
    int m = dislikes.size();
    for(int i=0;i<m;i++){
        int u = dislikes[i][0];
        int v = dislikes[i][1];
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    queue<int>q;
    vector<int>color(n+1,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            q.push(i);
            color[i]=0;
        }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &x:AdjList[node]){
            if(color[x]==-1){
                if(color[node]==0){
                    color[x]=1;
                }
                else{
                    color[x]=0;
                }
                q.push(x);
            }
            else{
                if(color[x]==color[node]){
                    return false;
                }
            }
        }
    }
    }
    return true;
    }
};
int main() {
    Solution s;

    // Sample test case
    int n = 4;
    vector<vector<int>> dislikes = {
        {1, 2},
        {1, 3},
        {2, 4}
    };

    bool result = s.possibleBipartition(n, dislikes);

    if(result)
        cout << "Possible to bipartition the graph" << endl;
    else
        cout << "Not possible to bipartition the graph" << endl;

    return 0;
}
