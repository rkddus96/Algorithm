#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            answer++;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();
                visited[cur] = true;
                
                for (int j = 0; j < n; j++)
                {
                    if (cur == j)
                        continue;
                    
                    if (!visited[j] && computers[cur][j] == 1)
                    {
                        q.push(j);
                    }
                }
            }
             
        }
    }
    
    
    return answer;
}