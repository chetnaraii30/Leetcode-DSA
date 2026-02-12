#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    unordered_map<char,int>mp;
    vector<char>charac;
    int n;
    cin>>n;
    string frag = "";
    vector<string>fragment;
    for(int i=0;i<n;i++){
       cin>>frag;
       fragment.push_back(frag);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(auto &e:fragment[i]){
            if(mp.find(e)==mp.end()){
                mp[e] = count++;
                charac.push_back(e);
            }
        }
    }
    int V = mp.size();
    vector<vector<int>>AdjList(V);
    vector<int>Indegree(V);
    for(int i=0;i<n;i++) {
    for(int j=0;j<fragment[i].size()-1;j++) {
        int u = mp[fragment[i][j]];
        int v = mp[fragment[i][j+1]];
        bool find=false;
        for(int x:AdjList[u]){
            if(x==v){
                find = true;
                break;
            }
        }
        if(!find){
            AdjList[u].push_back(v);
            Indegree[v]++;
        }
    }
}
   queue<int>q;
    for(int i=0;i<Indegree.size();i++){
        if(Indegree[i]==0){
            q.push(i);
        }
    }
    string result="";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        result += charac[node];
        for(int v:AdjList[node]){
            Indegree[v]--;
            if(Indegree[v]==0){
                q.push(v);
            }
        }
    }
    cout<<result<<endl;
    return 0;
}