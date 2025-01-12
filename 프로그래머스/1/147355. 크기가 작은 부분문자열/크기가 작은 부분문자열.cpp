#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int tsize = t.size();
    int psize = p.size();
    long long pnum = stoll(p); // p를 정수로 변환

    for (int i = 0; i <= tsize - psize; i++) { // 슬라이싱 범위 수정
        long long tnum = stoll(t.substr(i, psize)); // t의 부분 문자열을 정수로 변환
        if (tnum <= pnum) {
            answer++;
        }
    }
    
    return answer;
}
