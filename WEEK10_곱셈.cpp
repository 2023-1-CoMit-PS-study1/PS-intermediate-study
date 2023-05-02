#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull A, B, C;

ull multiple(ull base, ull power)
{
	if (power == 1) return base % C;

	if (power & 1)
	{
		return ((multiple(base, power - 1)) * (base)) % C;
	}
	else
	{
		ull temp = multiple(base, power >> 1);
		return (temp * temp) % C;
	}
}

int main()
{
	cin >> A >> B >> C;

	cout << multiple(A, B);

	return 0;
}
