#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k, t;
    cin >> k;
    
    stack<int> s;
    
    for(int i=0;i<k;i++) {
        cin >> t;
        if(t == 0)
            s.pop();
        else s.push(t);
    }
    int sum = 0;
    while(!s.empty()) {
        int curr = s.top(); s.pop();
        sum += curr;
    }
    
    cout << sum;
    
}