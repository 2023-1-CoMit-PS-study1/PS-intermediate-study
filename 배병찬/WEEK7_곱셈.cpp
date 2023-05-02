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

int a, b, c;

long long power(int b)
{
	if (b == 0)
		return 1;
	else if (b == 1)
		return a % c;
	else if (b % 2 == 0)
		return (power(b / 2) % c) * (power(b / 2) % c);
	else if (b % 2 == 1)
		return (power(b / 2) % c) * (power((b / 2) + 1) % c);
}

int main(void)
{
	cin >> a >> b >> c;
	cout << power(b) % c << endl;

	return 0;
}