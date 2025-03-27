#include <string>
#include <vector>
#include <cmath>

using namespace std;




long long solution(int k, int d) {
    long long answer = 0;
    
    
    for (long long a = 0; (a * k) <= d; a++)
    {
        long long MaxY = (long long)d * d - (a * k)*(a * k);
        answer += (long long)sqrt(MaxY) / k + 1; // 원점때문에 +1 
    }
   
    
    
    
    return answer;
}