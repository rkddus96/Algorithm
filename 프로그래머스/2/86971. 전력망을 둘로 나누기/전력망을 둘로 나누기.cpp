#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(vector<vector<int>>& graph, vector<bool>& visited, int start)
{
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    int count = 0;
    
    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        count++;
        
        for (int LinkedNode : graph[curNode])
        {
            if (!visited[LinkedNode])
            {
                q.push(LinkedNode);
                visited[LinkedNode] = true;
            }
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int minDiff = n;
    
    vector<vector<int>> baseGraph(n + 1);
    for (const auto& wire : wires)
    {
        baseGraph[wire[0]].push_back(wire[1]);
        baseGraph[wire[1]].push_back(wire[0]);
    }
    
    for (const auto& wire : wires)
    {
        vector<vector<int>> graph = baseGraph;
        
        int v1 = wire[0], v2 = wire[1];
        graph[v1].erase(remove(graph[v1].begin(), graph[v1].end(), v2), graph[v1].end());
        graph[v2].erase(remove(graph[v2].begin(), graph[v2].end(), v1), graph[v2].end());
        
        vector<bool> visited(n+1, false);
        int NodeCnt = BFS( graph, visited, wire[0]);
        
        minDiff = min(minDiff, abs(n-NodeCnt - NodeCnt));
    }
    
    
    
    
    answer = minDiff;
    
    
    return answer;
}