#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    
    
    for (long long number : numbers)
    {
        //첫번째 자리가 0이면 1증가시키고 끝
        if (number % 2 == 0)
        {
            answer.push_back(number+1);
            continue;
        }
        
        //첫번째 자리가 0이 아니라면
        long long tmp = number;
        int binaryDigits = 0;
        
        while (tmp >= 2)
        {
            tmp /= 2;
            binaryDigits++;
        }
        for (int i = 0; i <= binaryDigits+1; i++)
        {  
            //0인자리 구하기
            if (!(number & (1LL << i)))
            {
                number += (1LL << i);
                number ^= (1LL << (i-1));
                answer.push_back(number);
                break;
            }
            
        }
        
        
    }
    
    
    return answer;
}