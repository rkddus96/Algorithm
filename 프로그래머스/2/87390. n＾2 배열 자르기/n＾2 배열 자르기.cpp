#include <vector>
#include <algorithm>  // max() 사용을 위해 필요

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    int size = right - left + 1; // 필요한 배열 크기
    vector<int> answer(size);    // 미리 공간 할당 (push_back 제거)

    for (long long i = left; i <= right; i++) {
        int row = i / n;
        int col = i % n;
        answer[i - left] = max(row, col) + 1;  // 직접 할당
    }

    return answer;
}