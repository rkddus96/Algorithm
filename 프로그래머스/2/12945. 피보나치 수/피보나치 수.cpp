#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> memo(100001, 0);

int f(int num)
{
    if (num == 0) 
        return memo[0];
    else if (num == 1)
        return memo[1];
    
    if (memo[num] != 0)
        return memo[num];
    
    memo[num] = (f(num-2) + f(num-1)) % 1234567;
    return memo[num];
}


int solution(int n) {
    int answer = 0;
    memo[1] = 1;
    answer = f(n);
    
    return answer;
}