#include <iostream>
#include <string>
using namespace std;



int solution(string s)
{
   int answer = 1;
    int n = s.size();

    for (int center = 0; center < n; ++center) {
        // 홀수 길이 팰린드롬
        int l = center, r = center;
        while (l >= 0 && r < n && s[l] == s[r]) {
            answer = max(answer, r - l + 1);
            l--; r++;
        }

        // 짝수 길이 팰린드롬
        l = center, r = center + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            answer = max(answer, r - l + 1);
            l--; r++;
        }
    }


    return answer;
}