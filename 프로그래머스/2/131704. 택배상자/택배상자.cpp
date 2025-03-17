#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int orderIndex = 0;
    int i = 1;
    
    
    
    
    while (true)
    {
        if (order[orderIndex] == i)
        {
            answer++;
            orderIndex++;
            i++;
        }
        else if (!s.empty() && s.top() == order[orderIndex] )
        {
            s.pop();
            answer++;
            orderIndex++;
        }
        else if (i < order[orderIndex])
        {
            s.push(i);
            i++;
        }
        else
        {
            break;
        }
        
    }
        
    
    
    return answer;
}