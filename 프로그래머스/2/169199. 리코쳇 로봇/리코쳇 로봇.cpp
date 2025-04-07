#include <string>
#include <vector>
#include <queue>
#include <set>


using namespace std;

struct Point
{
    int y, x;
    
    Point(int y, int x) : y(y), x(x) {}
    
    bool operator==(Point other)
    {
        return y == other.y && x == other.x;
    }
    
    Point operator+(Point other)
    {
        return Point(y+other.y, x+other.x);
    }
};

bool isValid(Point p ,int n, int m)
{
    if (0 <= p.y && 0 <= p.x &&  p.y < n && p.x < m)
        return true;
    
    return false;
}

int solution(vector<string> board) {
    int answer = 0;
    vector<Point> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    Point StartPoint = {0, 0};
    Point TargetPoint = {0, 0};
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
            {
                StartPoint.y = i;
                StartPoint.x = j;
            }
            else if (board[i][j] == 'G')
            {
                TargetPoint.y = i;
                TargetPoint.x = j;
            }
        }
    }
    
    queue<pair<Point, int>> q;
    q.push({StartPoint, 0});
    visited[StartPoint.y][StartPoint.x] = true;
    
    while (!q.empty())
    {
        Point currentPoint = q.front().first;
        int currentCnt = q.front().second;
        q.pop();
        
        if (currentPoint.y == TargetPoint.y && currentPoint.x == TargetPoint.x)
        {
            answer = currentCnt;
            break;
        }
        
        for (Point d : direction)
        {
            Point NextPoint = currentPoint+d;
            if (isValid(NextPoint, n, m) && board[NextPoint.y][NextPoint.x] != 'D' )
            {
                Point lastPoint = NextPoint;
                NextPoint = NextPoint+d;
                while (isValid(NextPoint, n, m) && board[NextPoint.y][NextPoint.x] != 'D')
                {
                    lastPoint = NextPoint;
                    NextPoint = NextPoint+d;
                }
                
                if (!visited[lastPoint.y][lastPoint.x])
                {
                    q.push({lastPoint, currentCnt+1});
                    visited[lastPoint.y][lastPoint.x] = true;
                }
                
                
            }
        }
        
        
        
    }
    
    
    if (answer == 0)
        answer = -1;
    
    return answer;
}