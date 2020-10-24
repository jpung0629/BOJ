#include <list>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    list<int> lt;
    queue<int> q;
    int n, k;
    bool first = true;
    cin >> n >> k;

    for(int i=1; i <= n;i++) {
        lt.push_back(i);
    }

    auto it = lt.begin();
    while(!lt.empty()) {
        for(int i=0;i<k-1;i++) {
            it++;
            if(it == lt.end()) {
                it = lt.begin();
            }
        }

        q.push(*it);
        lt.erase(it++);
        if(it == lt.end()) it = lt.begin();
    }

    cout << "<";
    while(!q.empty()) {
        cout << q.front(); q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << ">" << endl;
}