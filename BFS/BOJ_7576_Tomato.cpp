#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int n = 0, m = 0;

int box[1002][1002];
int dist[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int result = -1;
queue<pair<int,int>> Q;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) Q.push({i,j});
            if(box[i][j] == 0) dist[i][j] = -1;
        }
    }

    int nx, ny;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        
        for(int dir=0;dir<4;dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}