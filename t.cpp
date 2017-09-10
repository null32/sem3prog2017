#include <cstdio>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <vector>

using namespace std;

void mark(vector<int>* field, int sz, int start, bool* marked)
{
	marked[start] = true;
	for (auto iter = field[start].begin(); iter != field[start].end(); ++iter)
	{
		if (!marked[*iter])
		{
			marked[*iter] = true;
			mark(field, sz, *iter, marked);
		}
	}
}

void solve()
{
	int cities, roads;
	scanf("%d %d", &cities, &roads);

	auto field = new vector<int>[cities];
	for (int i = 0; i < cities; i++)
		field[i] = *new vector<int>();


	for (int i = 0; i < roads; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		field[a - 1].push_back(b - 1);
		field[b - 1].push_back(a - 1);
	}

	auto marked = new bool[cities];
	memset(marked, false, cities);

	int res = -1;
	for (int i = 0; i < cities; i++)
	{
		if (marked[i])
			continue;
		res++;
		mark(field, cities, i, marked);
	}

	printf("%d\n", res);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
