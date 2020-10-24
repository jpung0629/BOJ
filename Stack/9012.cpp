#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    string str;
    int t;

    cin >> t;
    for(int c = 0; c < t; c++) {
        while(!s.empty()) s.pop();
        cin >> str;

        bool flag = true;
        for(auto ch : str) {
            if(ch == '('){
                s.push(ch);
            }
            if(ch == ')') {
                if(s.size() == 0) {
                    flag = false;
                    break;
                }
                s.pop();
            }
        }
        if(s.size() != 0) flag = false;
        cout << (flag ? "YES" : "NO") << endl;
        
    }
}