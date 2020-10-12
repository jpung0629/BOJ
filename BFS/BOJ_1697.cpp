#include <iostream>
#include <queue>
using namespace std;

queue<int> Q;
int dist[10002];
int n,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fill(dist, dist+10001, -1);

    dist[n] = 0;
    Q.push(n);
    while(dist[k] == -1) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur + 1, cur - 1, cur * 2}){
            if(dist[nxt] != -1) continue;
            if(nxt < 0 || nxt > 10000) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }    
    cout << dist[k];
}