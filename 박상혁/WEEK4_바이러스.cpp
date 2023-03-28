#include <iostream>
#include <vector>
#define N_MAX 100

using namespace std;

vector<short> graph[N_MAX + 1];
bool infected[N_MAX + 1];

short virus = 0;
void dfs(short curr)
{
	if (infected[curr]) return;

	infected[curr] = true;
	++virus;

	for (short& next : graph[curr])
	{
		dfs(next);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	short a, b;
	while (M--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	cout << virus - 1;
}
