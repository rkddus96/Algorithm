#include <string>
#include <vector>
#include <algorithm> // sort 함수 사용

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b) {
        // 인덱스 n의 문자 기준으로 우선 정렬
        if (a[n] != b[n]) {
            return a[n] < b[n];
        }
        // 인덱스 n의 문자가 같으면 전체 문자열로 정렬
        return a < b;
    });
    return strings;
}
