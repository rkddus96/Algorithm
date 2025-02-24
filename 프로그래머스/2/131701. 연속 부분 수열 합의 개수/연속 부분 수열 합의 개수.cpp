#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int vSize = elements.size();
    set<int> numbers;
    
    for (int length = 1; length <= vSize; length++)
    {
        
        //배열 순회
        for (int i = 0; i < vSize; i++)
        {
            int s = 0;
            //길이만큼 연속 순열의 합구하기
            for (int j = 0; j < length; j++)
            {
                int index = (i+j) % vSize;
                s += elements[index];
            }
            numbers.insert(s);
        }
        
    }
    
    answer = numbers.size();
    
    
    return answer;
}