#include <cstdio>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

void solve(pair<int, int>* arr, int sz)
{
	sort(arr + 1, arr + 1 + sz, [](pair<int, int> a, pair<int, int> b)
	{
		return 	a.first + max(a.second, b.first) + b.second <
			b.first + max(b.second, a.first) + a.second;
	});

	#ifdef DEBUG
	for (int i = 0; i <= sz + 1; i++)
		printf("%d - %d\n", arr[i].first, arr[i].second);
	#endif

	int time = 0;
	int latency = 0;
	for (int i = 1; i <= sz + 1; i++)
	{
		time += arr[i].first;
		if (latency + arr[i - 1].second > arr[i].first)
			latency += arr[i - 1].second - arr[i].first;
		else
			latency = 0;
	}

	printf("%d\n", time + latency);
}

int main()
{
	int sz;
	while (scanf("%d", &sz) != EOF)
	{
		auto arr = new pair<int, int>[sz + 2];
		arr[0] = make_pair(0, 0);
		for (int i = 1; i <= sz; i++)
			scanf("%d", &arr[i].first);
		for (int i = 1; i <= sz; i++)
			scanf("%d", &arr[i].second);
		solve(arr, sz);
	}
}
