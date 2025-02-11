#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> memo;
    //등수 메모
    for (int i = 0; i < players.size(); i++)
    {
        memo[players[i]] = i;
    }
    
    answer = players;
    for (string call : callings)
    {
        int i = memo[call];
        memo[call] = i-1;
        memo[answer[i-1]] = i;
        swap(answer[i], answer[i-1]);
    }
    
    return answer;
}