#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<int>> adj(N+1, vector<int>(N+1, INT_MAX));
    vector<int> dist(N+1, INT_MAX);
    dist[1] = 0;
    vector<bool> visited(N + 1, false);
    
    //그래프를 인접행렬로 만들기
    for (vector<int> e : road)
    {
        int u = e[0], v = e[1], w = e[2];
        if (w < adj[u][v])
        {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }
    

    
    for (int i = 1; i <= N; i++)
    {
        int minDist = INT_MAX;
        int u = -1;
        
        for (int j = 1; j <= N; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }
        
        if (u == -1)
        {
            break;
        }
        
        visited[u] = true;
        
        for (int v = 1; v <= N; v++)
        {
            if (adj[u][v] != INT_MAX && dist[u]+ adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }
    
    
    
    for (int d : dist)
    {
        if (d <= K)
        {
            answer++;
        }
    }
    

    return answer;
}