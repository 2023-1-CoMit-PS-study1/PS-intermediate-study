#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <string.h>
#pragma warning(disable: 4996)
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int tomato[1000][1000] = { 0, };
int visited[1000][1000] = { 0, };

queue<pair<int, int>> Q;
int m, n;

void BFS()
{
	while (!Q.empty())
	{
		pair<int, int> curr = { Q.front().first, Q.front().second };
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			{
				continue;
			}
			if (tomato[ny][nx] == 0 && visited[ny][nx] == 0)
			{
				visited[ny][nx] = visited[curr.second][curr.first] + 1;
				Q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n; // °¡·Î m, ¼¼·Î n
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i][j];
		}
	}

	for (int i = 0; i < n; i++) // yÁÂÇ¥
	{
		for (int j = 0; j < m; j++) // xÁÂÇ¥
		{
			if (tomato[i][j] == 1)
			{
				Q.push(make_pair(j, i));
			}
		}
	}

	BFS();

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	*/

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] > max)
			{
				max = visited[i][j];
			}
			if (tomato[i][j] == 0 && visited[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << max << endl;

	return 0;
}