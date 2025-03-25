#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void f(vector<vector<int>>& adj, vector<int>& dist, vector<int>& previousNode)
{
    queue<int> q;
    vector<bool> inQueue(dist.size(), false); // 중복 큐 삽입 방지용

    q.push(1);
    inQueue[1] = true;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        inQueue[curNode] = false;

        for (int i = 1; i < adj.size(); i++)
        {
            if (adj[curNode][i] != INT_MAX)
            {
                if (dist[curNode] + adj[curNode][i] < dist[i])
                {
                    dist[i] = dist[curNode] + adj[curNode][i];
                    previousNode[i] = curNode;

                    if (!inQueue[i]) {
                        q.push(i);
                        inQueue[i] = true;
                    }
                }
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<int>> adj(N + 1, vector<int>(N + 1, INT_MAX));
    vector<int> dist(N + 1, INT_MAX);
    vector<int> previousNode(N + 1, -1);
    dist[1] = 0;

    // 인접 행렬 구성 (양방향)
    for (vector<int> e : road)
    {
        int u = e[0], v = e[1], w = e[2];
        if (w < adj[u][v]) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }

    // 자기 자신으로 가는 거리는 0
    for (int i = 1; i <= N; i++) {
        adj[i][i] = 0;
    }

    f(adj, dist, previousNode);

    // 최단 거리가 K 이하인 노드 개수 세기
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}
