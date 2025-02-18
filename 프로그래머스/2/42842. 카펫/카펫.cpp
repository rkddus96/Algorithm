#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int col = 3;
    int row = 3;
    int totalnum = (brown - 8) / 2;
    //둘레
    int outlineLength = (col + row + totalnum) * 2 - 4;
    for (int i = 0; i <= totalnum/2; i++)
    {
        int extraCol = totalnum - i;
        int extraRow = i;
        //넓이
        int area = (col + extraCol) * (row + extraRow);
        if (area - outlineLength == yellow)
        {
            col += extraCol;
            row += extraRow;
            break;
        }
    }
    answer.push_back(col);
    answer.push_back(row);

    
    return answer;
}