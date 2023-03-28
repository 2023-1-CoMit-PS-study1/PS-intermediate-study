#include <iostream>
#define N_MAX 300

using namespace std;

int stairs[N_MAX + 1];
// memo[i][0]은 직전 칸을 밟지 않음. memo[i][1]은 직전 칸을 밟음
int memo[N_MAX + 1][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> stairs[i];
	}

	memo[1][0] = memo[1][1] = stairs[1];
	
	for (int i = 2; i <= N; ++i)
	{
		memo[i][0] = max(memo[i - 2][0], memo[i - 2][1]) + stairs[i];
		memo[i][1] = memo[i - 1][0] + stairs[i];
	}

	cout << max(memo[N][0], memo[N][1]);

	return 0;
}
