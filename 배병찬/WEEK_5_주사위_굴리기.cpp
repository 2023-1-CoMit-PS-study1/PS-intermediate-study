#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int n, m;
int arr[20][20];

int dice[7] = { 0,0,0,0,0,0,0 }; // 인덱스 0은 사용하지 않음
int x, y; // 주사위의 현재 위치 좌표

void roll_east()
{
	int nx = x + 1; int ny = y;
	if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		return;

	x = nx;

	int temp[7] = { 0, };
	temp[1] = dice[4];
	temp[2] = dice[2];
	temp[3] = dice[1];
	temp[4] = dice[6];
	temp[5] = dice[5];
	temp[6] = dice[3];

	for (int i = 0; i < 7; i++)
	{
		dice[i] = temp[i];
	}

	if (arr[ny][nx] == 0)
	{
		arr[ny][nx] = dice[6];
	}
	else
	{
		dice[6] = arr[ny][nx];
		arr[ny][nx] = 0;
	}

	cout << dice[1] << endl;

	return;
}

void roll_west()
{
	int nx = x - 1; int ny = y;
	if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		return;

	x = nx;

	int temp[7] = { 0, };
	temp[1] = dice[3];
	temp[2] = dice[2];
	temp[3] = dice[6];
	temp[4] = dice[1];
	temp[5] = dice[5];
	temp[6] = dice[4];

	for (int i = 0; i < 7; i++)
	{
		dice[i] = temp[i];
	}

	if (arr[ny][nx] == 0)
	{
		arr[ny][nx] = dice[6];
	}
	else
	{
		dice[6] = arr[ny][nx];
		arr[ny][nx] = 0;
	}

	cout << dice[1] << endl;

	return;
}

void roll_north()
{
	int nx = x; int ny = y - 1;
	if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		return;

	y = ny;

	int temp[7] = { 0, };
	temp[1] = dice[5];
	temp[2] = dice[1];
	temp[3] = dice[3];
	temp[4] = dice[4];
	temp[5] = dice[6];
	temp[6] = dice[2];

	for (int i = 0; i < 7; i++)
	{
		dice[i] = temp[i];
	}

	if (arr[ny][nx] == 0)
	{
		arr[ny][nx] = dice[6];
	}
	else
	{
		dice[6] = arr[ny][nx];
		arr[ny][nx] = 0;
	}

	cout << dice[1] << endl;

	return;
}

void roll_south()
{
	int nx = x; int ny = y + 1;
	if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		return;

	y = ny;

	int temp[7] = { 0, };
	temp[1] = dice[2];
	temp[2] = dice[6];
	temp[3] = dice[3];
	temp[4] = dice[4];
	temp[5] = dice[1];
	temp[6] = dice[5];

	for (int i = 0; i < 7; i++)
	{
		dice[i] = temp[i];
	}

	if (arr[ny][nx] == 0)
	{
		arr[ny][nx] = dice[6];
	}
	else
	{
		dice[6] = arr[ny][nx];
		arr[ny][nx] = 0;
	}

	cout << dice[1] << endl;

	return;
}

int main(void)
{
	int k;
	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int dir; cin >> dir;
		if (dir == 1)
			roll_east();
		else if (dir == 2)
			roll_west();
		else if (dir == 3)
			roll_north();
		else if (dir == 4)
			roll_south();
	}

	return 0;
}