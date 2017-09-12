#include <cstdio>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

void solve()
{
	int sz;
	scanf("%d", &sz);

	auto arr = new int[sz + 2];
	arr[0] = 0;
	arr[sz + 1] = 0;
	for (int i = 0; i < sz; i++)
		scanf("%d", &arr[i + 1]);

	sz += 2;

	int step;
	scanf("%d", &step);

	for (int i = sz - 2; i >= 0; i--)
	{
		int localmax = INT_MIN;
		for (int j = 1; j <= step && i + j < sz; j++)
			if (arr[i + j] > localmax)
				localmax = arr[i + j];
		arr[i] += localmax;

		#ifdef DEBUG
		for (int i = 0; i < sz; i++)
			printf("%d ", arr[i]);
		printf("\n");
		#endif
	}

	printf("%d\n", arr[0]);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
