#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, int> name; // �̸����� �˻��ϴ� �뵵�� map
vector<string> number; // ��ȣ�� �˻��ϴ� �뵵�� vector

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	// Index 0�� ���� ����
	name.insert(make_pair("None", 0));
	number.push_back("None");

	// ���ϸ��� ������ ����
	for (int i = 1; i <= n; i++)
	{
		string pokemon; cin >> pokemon;
		name.insert(make_pair(pokemon, i));
		number.push_back(pokemon);
	}
	// ���� Ǯ��
	for (int i = 0; i < m; i++)
	{
		string q; cin >> q;

		// ���ϸ� ��ȣ�� ������ �־��� ���
		if (q[0] >= '0' && q[0] <= '9')
		{
			int num = stoi(q);
			cout << number[num] << '\n';
		}
		// ���ϸ� �̸��� ������ �־��� ���
		else
		{
			cout << name[q] << '\n';
		}
	}

	return 0;
}