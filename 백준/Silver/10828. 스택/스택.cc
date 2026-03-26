#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    
    vector<int> s;
    
    while (t--)
    {
        string action;
        cin >> action;
        
       if (action == "push") {
            int element;
            cin >> element;
            s.push_back(element);
        }
        else if (action == "pop") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.back() << '\n';
                s.pop_back();
            }
        }
        else if (action == "top") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.back() << '\n';
        }
        else if (action == "size") {
            cout << s.size() << '\n';
        }
        else if (action == "empty") {
            cout << (s.empty() ? 1 : 0) << '\n';
        }
    }
}