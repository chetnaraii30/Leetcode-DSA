#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<char>> mat(n, vector<char>(m));;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat [i][j] = arr[i][j];
        }
    }
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    queue<pair<pair<int,int>,pair<int,int>>>q;
    vector<vector<int>>visited(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==1) continue;
            q.push({{i,j},{-1,-1}});
            visited[i][j]=1;
    while(!q.empty()){
        auto node = q.front().first;
        auto par = q.front().second; 
        int nfir = node.first;
        int nsec = node.second;
        int pfir = par.first;
        int psec = par.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = nfir + dx[i];
            int ny = nsec + dy[i];
            if(nx>=n||nx<0||ny>=m||ny<0||mat[nx][ny]!=mat[nfir][nsec]) continue;
            if(visited[nx][ny]==1){
                if(!(nx==pfir&&ny==psec)){
                    cout<<"Yes"<<endl;;
                    return 0;;
                }
            }
            else{
                visited[nx][ny]=1;
                q.push({{nx,ny},{nfir,nsec}});
            }
        }
    }

        }
    }
    
    cout<<"No";
    return 0;
}