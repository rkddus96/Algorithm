#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;


int solution(int x, int y, int n) {
    if (x == y)
        return 0;
    
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    
    q.push({x, 0});
    visited.insert(x);
    
    while (!q.empty())
    {
        int curr = q.front().first;
        int count = q.front().second;
        q.pop();
        
        int nextValues[] = {curr+n, curr*2, curr*3};
        
        for (int next : nextValues)
        {
            if (next == y)
                return count + 1;
            if (next < y && visited.find(next) == visited.end())
            {
                q.push({next, count+1});
                visited.insert(next);
            }
        }
    }
    
    
    
    
    return -1;
}