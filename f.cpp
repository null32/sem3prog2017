#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

void solve()
{
	int len;
	scanf("%d", &len);
	auto arr = new int[len];

	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + len, greater<int>());
	int count = 1;
	while (arr[0] == arr[count])
		count++;

	printf("%d\n", count);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
