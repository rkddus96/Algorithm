#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int element : arr)
    {
        if (element % divisor == 0)
        {
            answer.push_back(element);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }
    
    
    return answer;
}

