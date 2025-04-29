#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool finished = false;
vector<string> answer;

void DFS (string current, vector<vector<string>> &tickets,  vector<bool>& visited, 
          vector<string>& path, 
          int depth
        )
{
    if (finished)
        return;
        
    if (depth == tickets.size())
    {
        path.push_back(current);
        answer = path;
        finished = true;
        path.pop_back();
        return;
    }
    
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (!visited[i] && tickets[i][0] == current)
        {
            visited[i] = true;
            path.push_back(current);
            DFS(tickets[i][1], tickets, visited, path, depth+1);
            //백트래킹
            path.pop_back();
            visited[i] = false;
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> path;
    vector<bool> visited(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end(), [](const auto& a, const auto& b) {
        if (a[0] == b[0]) 
            return a[1] < b[1];
        return a[0] < b[0];
    });

    DFS("ICN", tickets, visited, path, 0);
    
    return answer;
}