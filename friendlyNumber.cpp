#include<iostream>
#include<vector>
using namespace std;
long long digitSum(long long n){
    long long s = 0;
    while(n>0){
        s += n%10;
        n /= 10;
    }
    return s;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long x;
        cin>>x;
        int ans=0;
        for(long long y=x;y<=x+90;y++){
            if(y-digitSum(y)==x){
                ans++;
            }
        }
        cout<<ans<<endl;
        t--;
    }
    
}