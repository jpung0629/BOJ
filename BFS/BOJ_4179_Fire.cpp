#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int dist1[1002][1002];
int dist2[1002][1002];

queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;
int n = 0, m = 0;

string maze[1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (maze[i][j] == 'F')
            {
                Q1.push({i, j});
                dist1[i][j] = 0;        
            }
            if (maze[i][j] == 'J')
            {
                Q2.push({i, j});
                dist2[i][j] = 0;    
            }
        }
    }

    int nx, ny;
    while (!Q1.empty())
    {
        auto cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maze[nx][ny] == '#' || dist1[nx][ny] >= 0)
                continue;

            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }

    while (!Q2.empty())
    {
        auto cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            };
            if (dist2[nx][ny] >= 0 || maze[nx][ny] == '#')
                continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
                continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
