#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
     vector<int> stack;
    int answer = 0;

    for (int x : ingredient) {
        stack.push_back(x);

        // 마지막 4개가 [1,2,3,1]이면 제거
        if (stack.size() >= 4 &&
            stack[stack.size() - 4] == 1 &&
            stack[stack.size() - 3] == 2 &&
            stack[stack.size() - 2] == 3 &&
            stack[stack.size() - 1] == 1) 
        {
            stack.erase(stack.end() - 4, stack.end()); // 햄버거 포장
            answer++;
        }
    }
    
    
    
    return answer;
}