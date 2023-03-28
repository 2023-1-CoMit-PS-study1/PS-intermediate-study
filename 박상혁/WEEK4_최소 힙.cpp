#include <iostream>
#include <queue>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, x;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> Q;
	while (N--)
	{
		cin >> x;
		if (x)
		{
			Q.push(x);
		}
		else
		{
			Q.empty() ? cout << "0\n" : cout << Q.top() << '\n';
			if (Q.size()) Q.pop();
		}
	}

	return 0;
}
