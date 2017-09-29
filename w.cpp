#include <cstdio>
#include <algorithm>
#include <functional>
#include <climits>

const int big = 10000;
using namespace std;

void solve()
{
	int sz, edges;
	scanf("%d %d", &sz, &edges);

	auto graph = new int*[sz];
	for (int i = 0; i < sz; i++)
	{
		graph[i] = new int[sz];
		for (int j = 0; j < sz; j++)
			graph[i][j] = i == j ? 0 : big;
	}

	for (int i = 0; i < edges; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a - 1][b - 1] = 0;
		graph[b - 1][a - 1] = 0;
	}

	for (int k = 0; k < sz; k++)
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", graph[a - 1][b - 1] == 0 ? 1 : 0);
	}
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
