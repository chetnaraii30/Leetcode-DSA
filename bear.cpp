#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,d,h;
    cin>>n>>d>>h;
    int source=1;
    vector<vector<int>>AdjList(n+1);
    if(h>d||d>n-1){
        cout<<-1<<endl;
        return 0;
    }
    if(d<2&&d==h&&(d*2<n)){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=h;i++){
        AdjList[i].push_back(i+1);
    }
    int hei = d-h;
    if(hei>h){
        cout<<-1<<endl;
        return 0;
    }
    int j = h+2;
    while(hei>0){
        AdjList[source].push_back(j);
        source = j;
        hei--;
        j++;
    }
    while(j<=n){
        AdjList[h].push_back(j);
        j++;
    }
    for(int i=1;i<=n;i++){
        for(int e:AdjList[i]){
            cout<<i<<" "<<e<<endl;
        }
    }
}