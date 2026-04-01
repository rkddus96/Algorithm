#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int length = prices.size();
    
    for (int i = 0; i < length; i++)
    {
        int end = i;
        for (int j = i+1; j < length; j++)
        {
            end++;
            if (prices[j] < prices[i])
                break;
        }
        
        answer.push_back(end-i);
    }
    
    
    return answer;
}