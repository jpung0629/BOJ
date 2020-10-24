#include <iostream>
#include <stack>
#include <queue>
#include <utility>

using namespace std;


int graph[1001][1001];
int visited[1001];
int main() {
    stack<int> stack;
    queue<int> queue;
    int n, m, v;
    int s, t;

    cin >> n >> m >> v;
    for(int i=0;i<=1001;i++) {
        fill(graph[i], graph[i] + 1000, 0);
    }
    fill(visited, visited + 1000, 0);
    for(int i=1;i<=n;i++) {
        for(int j = 1; j <=n; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    for(int i=0;i<m;i++) {
        cin >> s >> t;
        graph[s][t] = 1;
        graph[t][s] = 1;
    }

    queue.push(v);
    stack.push(v);
    while(!stack.empty()) {
        int curr = stack.top(); stack.pop();
        if(visited[curr]) continue;
                visited[curr] = true;
        cout << curr << " ";
        for(int i=m;i>=1;i--) {
            if(curr == i) continue;
            if(visited[i] || !graph[curr][i]) continue;
            stack.push(i);
       }
    }
}