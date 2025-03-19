#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    
    vector<int> answer(n * (n + 1) / 2);
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(i+1);
    }
    // 3으로 나눠서 0이면 외쪽 밑으로 1이면 오른쪽으로 2이면왼쪽 위로
    int direction = 0;
    int cnt = 1;
    int row = 0, col = 0;
    
    for (int i = n; i >= 1; i--)
    {
        if (direction % 3 == 0)
        {
            for (int j = 0; j < i; j++)
            {
                matrix[row++][col] = cnt++;
            }
            row--; col++;
        }
        else if (direction % 3 == 1)
        {
            for (int j = 0; j < i; j++)
            {
                matrix[row][col++] = cnt++;
            }
            row--; col -= 2;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                matrix[row--][col--] = cnt++;
            }
            row += 2; col++;
        }
        direction = (direction + 1) % 3;
    }
    int idx = 0;
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            answer[idx++] = matrix[i][j];
        }
    }
    
    
    return answer;
    
    
}