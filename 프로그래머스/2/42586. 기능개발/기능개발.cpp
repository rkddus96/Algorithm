#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int length = progresses.size();
    vector<bool> CompletedJobs(length, false);
    stack<int> PreparedJobs; 
    int front = 0;
    
    while (front < length)
    {
        int RemainingProgress = 100 - progresses[front];
        int day = (RemainingProgress % speeds[front]) == 0 ? RemainingProgress / speeds[front] : 
        RemainingProgress / speeds[front] + 1;
        int j = 0;
        
        for (int i = front; i < length; i++)
        {
            progresses[i] += speeds[i] * day;
            if (progresses[i] >= 100 && front == i)
            {
                front++;
                j++;
            }
            
        }
        answer.push_back(j);
        
    }
    
    return answer;
}