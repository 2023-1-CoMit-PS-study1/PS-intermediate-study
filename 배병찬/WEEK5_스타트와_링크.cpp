#include <iostream>
#include <vector>
#pragma warning(disable: 4996)
using namespace std;

int n;
int arr[20][20];

int result = 40000;

void check_stat(vector<int> start)
{
	int start_total = 0;
	int link_total = 0;

	vector<int> link;
	for (int i = 0; i < n; i++)
	{
		if (find(start.begin(), start.end(), i) == start.end()) // start에 없는 원소면
			link.push_back(i);
	}

	vector<int>::iterator iter;
	vector<int>::iterator iter2;

	for (iter = start.begin(); iter != start.end(); iter++)
	{
		for (iter2 = start.begin(); iter2 != start.end(); iter2++)
		{
			start_total += arr[*iter][*iter2];
		}
	}

	for (iter = link.begin(); iter != link.end(); iter++)
	{
		for (iter2 = link.begin(); iter2 != link.end(); iter2++)
		{
			link_total += arr[*iter][*iter2];
		}
	}

	int score = abs(start_total - link_total);
	if (result > score)
		result = score;
}

void select(vector<int> comb, int total, int r, int idx, int depth)
{
	if (r == 0)
	{
		check_stat(comb);
		return;
	}
	else if (total < depth)
	{
		return;
	}
	else
	{
		comb[idx] = depth;
		select(comb, total, r - 1, idx + 1, depth + 1);

		select(comb, total, r, idx, depth + 1);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> comb(n / 2);
	select(comb, n - 1, n / 2, 0, 0);

	cout << result << endl;

	return 0;
}