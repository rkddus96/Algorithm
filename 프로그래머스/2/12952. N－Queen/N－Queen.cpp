#include <string>
#include <vector>

using namespace std;

bool isValid(int row, int col, vector<int>& matrix)
{
    for (int i = 0; i < row; ++i)
    {
        if (matrix[i] == col || abs(matrix[i] - col) == row - i)
            return false;
    }
    return true;
}

void NQueen(int row,int& answer, vector<int>& matrix, int n)
{
    if (row == n) 
    {
        answer++;
        return;
    }

    for (int col = 0; col < n; ++col) 
    {
        if (isValid(row, col, matrix)) 
        {
            matrix[row] = col;
            NQueen(row + 1, answer, matrix, n);
        }
    }
}


int solution(int n) {
    int answer = 0;
    vector<int> matrix(n);
    NQueen(0, answer, matrix, n);
    
    
    
    
    return answer;
}