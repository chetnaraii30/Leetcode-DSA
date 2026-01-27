#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>ans;
       unordered_map<string,int>mp;
       int count=0;
        for(int i=0;i<recipes.size();i++){
            mp[recipes[i]]=count++;
        }
        for(int i=0;i<ingredients.size();i++){
            for(auto e:ingredients[i]){
                if(mp.find(e)==mp.end()){
                    mp[e]=count++;
                }
            }
        }
        for(int i=0;i<supplies.size();i++){
            if(mp.find(supplies[i])==mp.end()){
                mp[supplies[i]]=count++;
            }
        }
         int v = count;
        vector<vector<int>>AdjList(v);
        vector<int>Indegree(v,0);
        queue<int>q;
        for(int i=0;i<ingredients.size();i++){
            for(auto e:ingredients[i]){
                int mi = mp[e];
                int mr = mp[recipes[i]];
                AdjList[mi].push_back(mr);
                Indegree[mr]++;
                cout<<mi<<"->"<<mr<<endl;
            }
        }
        for (auto &s : supplies) {
        q.push(mp[s]);
}
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int e:AdjList[node]){
                Indegree[e]--;
                if(Indegree[e]==0){
                    q.push(e);
                    ans.push_back(recipes[e]);
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution s;

    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {
        {"yeast", "flour"},
        {"bread", "ham"},
        {"sandwich", "meat"}
    };
    vector<string> supplies = {"yeast", "flour", "ham", "meat"};

    vector<string> result = s.findAllRecipes(recipes, ingredients, supplies);

    cout << "Possible Recipes: ";
    for (auto &r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}