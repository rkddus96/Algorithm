#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int cSize = citations.size();
    sort(citations.begin(), citations.end());
    for (int i = 0; i < cSize; i++)
    {
        if (citations[i] >= (cSize - i))
        {
            answer = cSize-i;
            break;
        }
    }
    
    return answer;
}