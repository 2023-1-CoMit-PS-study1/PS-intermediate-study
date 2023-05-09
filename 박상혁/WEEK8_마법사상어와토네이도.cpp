#include <iostream>

using namespace std;
using sh = short;
using ui = unsigned int;

constexpr sh MAX_N = 499 + 4;
constexpr sh MID = MAX_N / 2;

struct point
{
	sh x, y;
};

ui sand[MAX_N][MAX_N];

float ratio[] = { 0.01, 0.01, 0.07, 0.07, 0.1, 0.1, 0.05, 0.02, 0.02 };
sh dx_left[] = { 1, 1, 0, 0, -1, -1, -2, 0, 0 };
sh dy_left[] = { -1, 1, -1, 1, -1, 1, 0, -2, 2 };


void move_onestep(point& curr, int command)
{
	sh x, y;
	ui init_amount;
	ui move_amount;
	ui remain;
	
	switch (command)
	{
	// left
	case 1:
	{
		(curr.x)--;
		x = curr.x, y = curr.y;
		init_amount = sand[y][x];
		remain = init_amount;

		for (int i = 0; i < 9; ++i)
		{
			move_amount = static_cast<ui>(static_cast<float>(init_amount) * ratio[i]);
			sand[y + dy_left[i]][x + dx_left[i]] += move_amount;
			remain -= move_amount;
		}
		sand[y][x - 1] += remain;
		break;
	}
	// right
	case 2:
	{
		(curr.x)++;
		x = curr.x, y = curr.y;
		init_amount = sand[y][x];
		remain = init_amount;

		for (int i = 0; i < 9; ++i)
		{
			move_amount = static_cast<ui>(static_cast<float>(init_amount) * ratio[i]);
			sand[y + dy_left[i]][x - dx_left[i]] += move_amount;
			remain -= move_amount;
		}
		sand[y][x + 1] += remain;
		break;
	}
	// down
	case 3:
	{
		(curr.y)++;
		x = curr.x, y = curr.y;
		init_amount = sand[y][x];
		remain = init_amount;

		for (int i = 0; i < 9; ++i)
		{
			move_amount = static_cast<ui>(static_cast<float>(init_amount) * ratio[i]);
			sand[y - dx_left[i]][x + dy_left[i]] += move_amount;
			remain -= move_amount;
		}
		sand[y + 1][x] += remain;
		break;
	}
	// up
	default:
	{
		(curr.y)--;
		x = curr.x, y = curr.y;
		init_amount = sand[y][x];
		remain = init_amount;

		for (int i = 0; i < 9; ++i)
		{
			move_amount = static_cast<ui>(static_cast<float>(init_amount) * ratio[i]);
			sand[y + dx_left[i]][x + dy_left[i]] += move_amount;
			remain -= move_amount;
		}
		sand[y - 1][x] += remain;
		break;
	}
	}

	sand[y][x] -= init_amount;
}

void move_tornado(point& curr, sh N)
{
	// left: 1
	move_onestep(curr, 1);

	// down: N - 2
	for (int i = 0; i < N - 2; ++i)
	{
		move_onestep(curr, 3);
	}

	// right N - 1
	for (int i = 0; i < N - 1; ++i)
	{
		move_onestep(curr, 2);
	}

	// up N - 1
	for (int i = 0; i < N - 1; ++i)
	{
		move_onestep(curr, 4);
	}

	// left N - 1
	for (int i = 0; i < N - 1; ++i)
	{
		move_onestep(curr, 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	sh N;
	cin >> N;

	point left_top = { MID - N / 2, MID - N / 2 }, right_bottom = { MID + N / 2, MID + N / 2 };

	ui total_sand = 0;

	for (sh i = left_top.y; i <= right_bottom.y; ++i)
	{
		for (sh j = left_top.x; j <= right_bottom.x; ++j)
		{
			cin >> sand[i][j];
			total_sand += sand[i][j];
		}
	}

	point start = { MID, MID };
	for (sh n = 3; n <= N; n += 2)
	{

		move_tornado(start, n);
	}

	ui remain_sand = 0;
	for (sh i = left_top.y; i <= right_bottom.y; ++i)
	{
		for (sh j = left_top.x; j <= right_bottom.x; ++j)
		{
			remain_sand += sand[i][j];
		}
	}

	cout << total_sand - remain_sand;

	return 0;
}
