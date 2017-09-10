#include <cstdio>

int money[] = { 10, 20, 50, 100, 200, 500 };

void solve()
{
	int val = 0;
	scanf("%d", &val);
	int res = 0;
	for (int i = 5; i >= 0; i--)
	{
		res += val / money[i];
		val %= money[i];
	}

	printf("%d\n", val == 0 ? res : -1);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
