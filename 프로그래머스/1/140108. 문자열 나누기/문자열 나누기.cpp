#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int xCount = 0;
    int notxCount = 0;
    char x = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == x)
            xCount++;
        else
            notxCount++;
        
        if (xCount == notxCount || i == s.size()-1)
        {
            answer++;
            if (i < s.size()-1)
                x = s[i+1];
            
        }
        
    }
    
    return answer;
}