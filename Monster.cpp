#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int count=0;
    string ans="";
    vector<vector<char>>mat(n,vector<char>(m));
    vector<vector<int>>visited(n,vector<int>(m,-1));
    queue<pair<int,int>>q;
    vector<vector<char>> dir(n, vector<char>(m));
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<int>> monsterTime(n, vector<int>(m,1e9));
    vector<vector<int>> distA(n, vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
     bool foundA=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='A'){
                visited[i][j]=1;
                distA[i][j]=0;
                q.push({i,j});
                foundA=true;
                break;
            }
        }
        if(foundA) break;
    }
    int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
char move[4] = {'L','U','R','D'};

    queue<pair<int,int>> mq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='M'){
                mq.push({i,j});
                monsterTime[i][j]=0;
            }
        }
    }
    while(!mq.empty()){
        int x = mq.front().first;
        int y = mq.front().second;
        mq.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||mat[nx][ny]=='#') continue;
            if(monsterTime[nx][ny] > monsterTime[x][y]+1){
                monsterTime[nx][ny]=monsterTime[x][y]+1;
                mq.push({nx,ny});
            }
        }
    }

    bool find=false;
    int x1=-1;
    int y1=-1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if((x==0||x==n-1||y==m-1||y==0)&&distA[x][y] < monsterTime[x][y]){
            x1 = x;
            y1=y;
            find = true;
            cout<<"YES"<<endl;
            break;
        }
        for(int i=0;i<4;i++){
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if(nx>=n||nx<0||ny>=m||ny<0||mat[nx][ny]=='#'|| mat[nx][ny]=='M') continue;
        if(visited[nx][ny]==-1 && distA[x][y]+1 < monsterTime[nx][ny]){
            q.push({nx,ny});
            distA[nx][ny]=distA[x][y]+1;
            parent[nx][ny]={x,y};
            dir[nx][ny]=move[i];
            visited[nx][ny]=1;
        }
    }
    }
    if(!find){
        cout<<"NO"<<endl;
        return 0;
    }
     while(x1!=-1 && y1!=-1 &&
          parent[x1][y1]!=make_pair(-1,-1)){
        count++;
        ans.push_back(dir[x1][y1]);
        auto p=parent[x1][y1];
        x1=p.first;
        y1=p.second;
    }
    reverse(ans.begin(),ans.end());
    cout<<count<<endl;
    cout<<ans<<endl;
}