#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int startIdx = 0;
    int endIdx = 0;
    int left = 0, right = 0;
    int partialSum = 0;
    int minLength = INT_MAX;
    while (right < sequence.size())
    {
        //추가
        partialSum += sequence[right];
        
        //검사
        while (partialSum >= k)
        {
            if (partialSum == k && (right - left) < minLength)
            {
                minLength = right - left;
                startIdx = left;
                endIdx = right;
                
            }
            
            partialSum -= sequence[left];
            left++;
        }
        
        
        //이동
        right++;
        
    }
    
    
    answer.push_back(startIdx);
    answer.push_back(endIdx);
    

    return answer;
}