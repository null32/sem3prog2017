#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <functional>

using namespace std;

#define N 10001
bool a[N];

void solve()
{
	int sz;
	scanf("%d", &sz);

	int count = 0, temp;
	for (int i = 0; i < sz; i++)
	{
		scanf("%d", &temp);
		if (temp < 0)
			temp = 0 - temp;
		if (a[temp])
			count++;
	}

	printf("%d\n", count);
}

int main()
{
	memset(a, false, N);

	for (int i = 4; i < N; i += 4)
		a[i] = true;
	for (int i = 7; i < N; i += 7)
		a[i] = false;

	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
