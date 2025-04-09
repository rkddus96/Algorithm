#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> points;
    points.push_back(k);
    while (k > 1)
    {
        if (k % 2 == 0)
        {
            k /= 2;
        }
        else
        {
            k = (k*3) + 1;
        }
        points.push_back(k);
    }
    int n = points.size();
    vector<double> area(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        area[i] = (points[i] + points[i + 1]) / 2.0;
    }
    
     // 누적합 (prefix sum) 계산
    vector<double> prefix(n, 0.0); // prefix[0] = 0.0
    for (int i = 0; i < n - 1; ++i) {
        prefix[i + 1] = prefix[i] + area[i];
    }

    // 각 ranges에 대해 누적합에서 구간합을 뽑아냄
    for (auto range : ranges) {
        int a = range[0];
        int b = range[1];
        int end = n - 1 + b;  // n-1: 구간의 마지막 index

        if (a > end) {
            answer.push_back(-1.0);
        } else {
            answer.push_back(prefix[end] - prefix[a]);
        }
    }
    
    
    return answer;
}