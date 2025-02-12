#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int maxX = park[0].size()-1;
    int maxY = park.size()-1;
    int x = 0;
    int y = 0;
    //시작 위치 저장 
    for (int i = 0; i <= maxY; i++)
    {
        for (int j = 0; j <= maxX; j++)
        {
            if (park[i][j] == 'S')
            {
                x = j;
                y = i;
            }
            
        }
    }
    
    //이동 시작
    for (string route : routes)
    {
        string direction = route.substr(0, 1);
        int distance = stoi(route.substr(2));
        bool cango = true;
        
        if (direction == "E")
        {
            // 초과하면 넘어가기
            if (x+distance > maxX)
            {
                continue;
            }
            //장애물 만나면 넘어가기
            for (int i = 1; i <= distance; i++)
            {
                if (park[y][x+i] == 'X')
                {
                    cango = false;
                    break;
                }
                    
            }
            
            if (cango)
                x += distance;
        }
        else if (direction == "W")
        {
            // 초과하면 넘어가기
            if (x-distance < 0)
            {
                continue;
            }
            //장애물 만나면 넘어가기
            for (int i = 1; i <= distance; i++)
            {
                if (park[y][x-i] == 'X')
                {
                    cango = false;
                    break;
                }
            }
            if (cango)
                x -= distance;
        }
        else if (direction == "N")
        {
            // 초과하면 넘어가기
            if (y-distance < 0)
            {
                continue;
            }
            //장애물 만나면 넘어가기
            for (int i = 1; i <= distance; i++)
            {
                if (park[y-i][x] == 'X')
                {
                    cango = false;
                    break;
                }
            }
            
            if (cango)
                y -= distance;
        }
        else
        {
            // S방향
            // 초과하면 넘어가기
            if (y+distance > maxY)
            {
                continue;
            }
            //장애물 만나면 넘어가기
            for (int i = 1; i <= distance; i++)
            {
                if (park[y+i][x] == 'X')
                {
                    cango = false;
                    break;
                }
            }
            
            if (cango)
                y += distance;
        }
    }
    
    answer.push_back(y);
    answer.push_back(x);
    
    return answer;
}