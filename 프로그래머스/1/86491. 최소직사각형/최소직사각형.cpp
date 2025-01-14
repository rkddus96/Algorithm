#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int ss = sizes.size();

    int maxw = 0;
    int maxh = 0;
    
    for (vector<int> size : sizes)
    {
        int width = max(size[0], size[1]);
        int height = min(size[0], size[1]);
        
        maxw = max(maxw, width);
        maxh = max(maxh, height);
    }
    
    answer = maxw * maxh;
    
    
    return answer;
}