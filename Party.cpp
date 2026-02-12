#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    vector<vector<int>> AdjList(n + 1);
    vector<int> Indegree(n + 1);
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        int u = arr[i];
        int v = j;
        if (u == -1)
        {
            j++;
            continue;
        }
        j++;
        AdjList[u].push_back(v);
        Indegree[v]++;
    }
    queue<int> q;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Indegree[i] == 0)
        {
            q.push(i);
        }
    }
    for (int i = 0; i < n; i++)
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                for (int e : AdjList[node])
                {
                    Indegree[e]--;
                    if (Indegree[e] == 0)
                    {
                        q.push(e);
                    }
                }
            }
            count++;
        }
    cout << count << endl;
}