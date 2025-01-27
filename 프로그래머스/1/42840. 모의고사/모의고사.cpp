#include <string>
#include <vector>

using namespace std;

int f1(vector<int> &answer, vector<int> &arr)
{
    int answerCount = 0;
    for (int i = 0 ; i < answer.size(); i++)
    {
        if (answer[i] == arr[i%arr.size()])
        {
            answerCount++;
        }
    }
    
    return answerCount;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int amax = 0;
    int aCount = f1(answers, a);
    int bCount = f1(answers, b);
    int cCount = f1(answers, c);
    vector<int> ret {0, aCount, bCount, cCount};
    for (int i = 1; i <= 3; i++)
    {
        if (amax < ret[i])
        {
            amax = ret[i];
        }
    }
    
    for (int i = 1; i <= 3; i++)
    {
        if (amax == ret[i])
        {
            answer.push_back(i);
        }
    }
    
    
    return answer;
}