#include <vector>
#include <queue>

using namespace std;

struct Position
{
    int y;
    int x;
    Position(int y, int x) : y(y), x(x) {}
    
    bool operator==(const Position& other) const 
    {
        return x == other.x && y == other.y;
    }
    
    Position operator+(const Position& other) const
    {
        return Position(y+other.y, x+other.x);
    }
};

bool isValid(Position p, int n, int m) {
    return p.y >= 0 && p.y < n && p.x >= 0 && p.x < m;
}

void BFS(vector<vector<int>>& maps, int& answer)
{
    int n = maps.size();
    int m = maps[0].size();
    queue<Position> q;
    vector<vector<int>> distance(n, vector<int>(m, 10001));
    Position dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 우하좌상
    
    distance[0][0] = 1;
    q.push(Position(0, 0));
                                 
    while (!q.empty())
    {
        Position currentP = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            Position nextP = currentP + dir[i];
            if (isValid(nextP, n, m) && maps[nextP.y][nextP.x] && 
                distance[currentP.y][currentP.x] + 1< distance[nextP.y][nextP.x])
            {
                distance[nextP.y][nextP.x] = distance[currentP.y][currentP.x] + 1;
                q.push(nextP);
            }
        }
        
    }
  
    answer = (distance[n-1][m-1] == 10001) ? -1 : distance[n-1][m-1];
    
    
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    BFS(maps, answer);
    
    return answer;
}