#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> graph(n+1);
    
    for (auto road : roads)
    {
        graph[road[0]].push_back(road[1]); 
        graph[road[1]].push_back(road[0]); 
    }
    
    for (int start : sources)
    {
        int sd = 0;
        
        if (start == destination)
        {
            answer.push_back(sd);
            continue;
        }
        
        queue<int> q;
        vector<int> dist(n+1, -1);
        
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for (auto neighbor : graph[cur])
            {
                if (dist[neighbor] == -1 )
                {
                    dist[neighbor] = dist[cur] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        if (dist[destination] != -1)
        {
            answer.push_back(dist[destination]);
        }
        else
        {
            answer.push_back(-1);
        }
        
    }
    
    
    
    return answer;
}