#include <iostream>
#include <queue>
#define N_MAX 1000

using namespace std;

struct point
{
	int x, y;
};

point delta[4] = { point{1, 0}, point{0, 1}, point{-1, 0}, point{0, -1} };

int tomatoes[N_MAX][N_MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> M >> N;

	queue<point> Q;
	int input;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tomatoes[i][j];
			if (1 == tomatoes[i][j])
			{
				Q.push(point{ j, i });
			}
		}
	}

	point temp{};
	point next{};
	while (Q.size())
	{
		temp = Q.front();
		Q.pop();

		for (point& d : delta)
		{
			next = { temp.x + d.x, temp.y + d.y };
			if (static_cast<unsigned int>(next.x) < M && static_cast<unsigned int>(next.y) < N)
			{
				if (!tomatoes[next.y][next.x])
				{
					tomatoes[next.y][next.x] = tomatoes[temp.y][temp.x] + 1;
					Q.push(next);
				}
				else if(tomatoes[next.y][next.x] != -1)
				{
					tomatoes[next.y][next.x] = min(tomatoes[next.y][next.x], tomatoes[temp.y][temp.x] + 1);
				}
			}
		}
	}

	int count = 1;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tomatoes[i][j])
			{
				count = max(count, tomatoes[i][j]);
			}
			else
			{
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << count - 1;

	return 0;
}
