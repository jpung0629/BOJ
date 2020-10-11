/**
 * BOJ 1926 Painting
 * https://www.acmicpc.net/problem/1926
 * */
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

queue<pair<int, int>> Q;

int board[500][500] = {0, };
int visited[500][500] = {0, };
int h = 0, w = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int num_of_paint = 0;
int max_width_paint = 0;
int temp_size = 0;

int nx = 0;
int ny = 0;
pair<int, int> curr;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	// Get board data.
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] || board[i][j] == 0)
				continue;

			num_of_paint++;
			temp_size = 0;
			visited[i][j] = 1;
			Q.push({i, j});
			while (!Q.empty())
			{
				pair<int, int> curr = Q.front();
				Q.pop();
				temp_size++;
				for (int dir = 0; dir < 4; dir++)
				{
					nx = curr.X + dx[dir];
					ny = curr.Y + dy[dir];
					if (nx < 0 || nx >= h || ny < 0 || ny >= w)
						continue;
					if (visited[nx][ny] || board[nx][ny] != 1)
						continue;
					Q.push({nx, ny});
					visited[nx][ny] = 1;
				}
			}

			if (temp_size > max_width_paint)
				max_width_paint = temp_size;
		}
	}

	cout << num_of_paint << '\n' << max_width_paint;
}
