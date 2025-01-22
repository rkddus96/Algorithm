#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    // 먹고 돌려 받는 갯수
    int ret = 0;
    //남은 병의 갯수
    int r = n;
    //
    int count = 0;
    
    
    while (r >= a)
    {
        ret = (r/a) * b;
        r = r%a;
        count += ret;
        
        r += ret;
    }
    
    
    answer = count;
    
    return answer;
}