#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int i = 0;
    stack<char> stk;
    
    for (char digit : number)
    {
        while( !stk.empty() && stk.top() < digit && i < k)
        {
            stk.pop();
            i++;
        }
        stk.push(digit);
    }
    
    while (i < k)
    {
        stk.pop();
        i++;
    }
    
    while (!stk.empty())
    {
        answer = stk.top() + answer;
        stk.pop();
    }
    
    
    
    return answer;
}