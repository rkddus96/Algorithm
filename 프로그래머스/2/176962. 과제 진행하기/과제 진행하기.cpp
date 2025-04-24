#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

int ToMinutes(string Time)
{
    int hour = stoi(Time.substr(0,2));
    int minute = stoi(Time.substr(3, 2));
    
    return hour*60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> pausedJobs;
    
    sort(plans.begin(), plans.end(), [](const auto a, const auto b) {
        return a[1] < b[1];
    });
    
    int CurrentTime = ToMinutes(plans[0][1]);
    
    for (int i = 0; i < plans.size(); i++)
    {
        vector<string> plan = plans[i];
        
        //계획 꺼내기
        string SubjectName = plan[0];
        int StartTime = ToMinutes(plan[1]);
        int PlayTime = stoi(plan[2]);
        
        int timeGap;
        if (i < plans.size() - 1)
            timeGap = ToMinutes(plans[i+1][1]) - StartTime;
        else
            timeGap = INT_MAX;
        
        if (PlayTime <= timeGap )
        {
            CurrentTime += PlayTime;
            timeGap -= PlayTime;
            answer.push_back(SubjectName);
            
            while (!pausedJobs.empty() && timeGap > 0)
            {
                auto [pausedName, remainingTime] = pausedJobs.top();
                pausedJobs.pop();
                
                if (remainingTime <= timeGap)
                {
                    CurrentTime += remainingTime;
                    timeGap -= remainingTime;
                    answer.push_back(pausedName);
                }
                else
                {
                    CurrentTime += timeGap; 
                    pausedJobs.push({pausedName, remainingTime-timeGap});
                    timeGap = 0;
                }
                
            }
            
        }
        else
        {
            CurrentTime += timeGap;
            pausedJobs.push({SubjectName, PlayTime-timeGap});
        }
        
        
    }
    
    while (!pausedJobs.empty()) {
        answer.push_back(pausedJobs.top().first);
        pausedJobs.pop();
    }
    
    
    return answer;
}