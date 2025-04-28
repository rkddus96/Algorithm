#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find (int x)
{
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}

bool unionSet(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[y] = x;
        return true;
    }
        
    return false;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), [](const auto &a, const auto &b) {
       return a[2] < b[2]; 
    });
    
    parent.resize(n);
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    
    for (auto edge : costs)
    {
        int v1 = edge[0];
        int v2 = edge[1];
        int cost = edge[2];
        
        if (unionSet(v1, v2))
        {
            answer += cost;
        }
        
    }
    
    
    return answer;
}