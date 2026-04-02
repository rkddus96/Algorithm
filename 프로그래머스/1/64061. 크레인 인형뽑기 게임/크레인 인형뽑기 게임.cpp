#include <string>
#include <vector>
#include <stack>


using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int n = board.size();
    stack<int> lanes[n];
    stack<int> bucket;
    //stack으로 변형하기
    for (int i = n-1; i >= 0; --i)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
            {
                int e = board[i][j];
                lanes[j].push(e);
            }
        }
    }
    
    
    for (int x : moves)
    {
        if (lanes[x-1].size())
        {
            int doll = lanes[x-1].top();
            lanes[x-1].pop();
            
            if (!bucket.empty() && bucket.top() == doll)
            {
                bucket.pop();
                answer += 2;
            }
            else
            {
                bucket.push(doll);
            }
        }
    }
    
    return answer;
}