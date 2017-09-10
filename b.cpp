#include <cstdio>
#include <algorithm>

using namespace std;

void solve()
{
	int sz = 0;
	scanf("%d", &sz);

	auto field = new int*[sz];
	for (int i = 0; i < sz; i++)
	{
		field[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++)
			scanf("%d", &field[i][j]);
	}

	for (int i = 1; i < sz; i++)
		for (int j = 0; j < i + 1; j++)
		{
			field[i][j] += max(j == 0 ? 0 : field[i - 1][j - 1], j == i ? 0 : field[i - 1][j]);
		}

	sort(field[sz - 1], field[sz - 1] + sz);
	printf("%d\n", field[sz - 1][sz - 1]);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
