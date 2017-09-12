#include <cstdio>

void solve()
{
	int sz;
	scanf("%d", &sz);
	auto arr = new int[sz];
	for (int i = 0; i < sz; i++)
		scanf("%d", &arr[i]);

	int min = 100;
	int max = -100;
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] == max)
			arr[i] = min;
		else if (arr[i] == min)
			arr[i] = max;
	}

	for (int i = 0; i < sz - 1; i++)
		printf("%d ", arr[i]);
	printf("%d\n", arr[sz - 1]);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
