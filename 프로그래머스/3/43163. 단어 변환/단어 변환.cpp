#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    queue<string> q;
    vector<bool> visited(words.size(), false);

    string currentString = begin;

    while (currentString != target)
    {
        bool foundNext = false;
        for (int i = 0; i < words.size(); i++)
        {
            if (visited[i])
                continue;
            // 문자 하나만 다르거나 방문하지 않았다면
            int diffCnt = 0;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (currentString[j] != words[i][j])
                    diffCnt++;
            }
            if (diffCnt == 1)
            {
                currentString = words[i];
                visited[i] = true;
                answer++;
                foundNext = true;
                break;
            }
        }
        if (!foundNext)
            return 0;
    }
    
    return answer;
}