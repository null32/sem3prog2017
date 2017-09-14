#include <cstdio>
#include <algorithm>
#include <functional>
#include <utility>
#include <memory.h>
#include <climits>
#include <list>
#include <vector>

using namespace std;

int dijkstra(vector<list<pair<int, int>>> graph, int start, int finish)
{
	auto marked = new bool[graph.size()];
	memset(marked, false, graph.size());
	auto cost = new int[graph.size()];
	for (int i = 0; i < graph.size(); i++)
		cost[i] = INT_MAX;

	cost[start] = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		int pos = 0;
		int minCost = INT_MAX;
		for (int j = 0; j < graph.size(); j++)
			if (cost[j] < minCost && !marked[j])
			{
				pos = j;
				minCost = cost[j];
			}

		marked[pos] = true;
		for (auto iter = graph[pos].begin(); iter != graph[pos].end(); ++iter)
			cost[(*iter).first] = min(cost[(*iter).first], (*iter).second + cost[pos]);

		#ifdef DEBUG
		printf("after node: %d\n", pos);
		for (int j = 0; j < graph.size(); j++)
			printf("%d ", cost[j]);
		printf("\n");
		#endif
	}

	return cost[finish];
}

void solve()
{
	int sz, edges;
	scanf("%d %d", &sz, &edges);

	auto graph = *new vector<list<pair<int, int>>>();
	for (int i = 0; i < sz; i++)
		graph.push_back(*new list<pair<int, int>>());

	for (int i = 0; i < edges; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		graph[a - 1].push_back(make_pair(b - 1, c));
		graph[b - 1].push_back(make_pair(a - 1, c));
	}

	int start, finish;
	scanf("%d %d", &start, &finish);

	int res = dijkstra(graph, start - 1, finish - 1);
	if (res == INT_MAX)
		puts("infinity");
	else
		printf("%d\n", res);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
