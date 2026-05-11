#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int GoalMax = goal.size();
    int front1 = 0;
    int front2 = 0;
    int frontForGoal = 0;
    
    for (string w : goal)
    {
        if (cards1[front1] == w)
            front1++;
        else if (cards2[front2] == w)
            front2++;
        else
            return "No";
    }
    
    
    return "Yes";
}