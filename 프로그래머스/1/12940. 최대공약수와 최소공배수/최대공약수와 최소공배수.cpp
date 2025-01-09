#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    int big, small;
    
    if ( a > b )
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }
    
    
    
    if (big % small == 0)
    {
        return small;
    }
    else
    {
        int r = big % small;
        return GCD(small, r);
    }
}

int LCM (int a ,int b, int gcd)
{
    int big, small;
    
    if ( a > b )
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }
    
    if (big % small == 0)
    {
        return big;
    }
    else
    {
        return big * small / gcd;
    }
    
    
}
    

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd = GCD(n, m);
    answer.push_back(gcd);
    
    int lcm = LCM(n, m, gcd);
    answer.push_back(lcm);
    
    return answer;
}