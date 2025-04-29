#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels(N); // {무게, 가치}
    vector<int> bags(K);

    for (int i = 0; i < N; ++i)
    {
        int m, v;
        cin >> m >> v;
        jewels[i] = {m, v};
    }

    for (int i = 0; i < K; ++i)
        cin >> bags[i];

    // 무게 기준으로 보석 정렬
    sort(jewels.begin(), jewels.end());
    // 가방 용량 오름차순 정렬
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long totalValue = 0;
    int j = 0;

    for (int i = 0; i < K; ++i)
    {
        while (j < N && jewels[j].first <= bags[i])
        {
            pq.push(jewels[j].second); // 가치만 저장
            ++j;
        }

        if (!pq.empty())
        {
            totalValue += pq.top();
            pq.pop(); // 가장 가치 높은 보석 사용
        }
    }

    cout << totalValue;
}
