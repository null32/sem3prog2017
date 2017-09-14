#include <cstdio>
#include <algorithm>
#include <functional>
#include <cstring>
#include <set>

using namespace std;

bool isConnected(set<int>* field, int sz, int index = 0, bool* marked = nullptr)
{
	if (marked == nullptr)
	{
		marked = new bool[sz];
		memset(marked, 0, sz);
	}

	marked[index] = true;
	for (auto iter = field[index].begin(); iter != field[index].end(); ++iter)
	{
		if (!marked[*iter])
			isConnected(field, sz, *iter, marked);
	}
	if (index == 0)
	{
		for (int i = 0; i < sz; i++)
			if (!marked[i])
				return false;
	}
	return true;
}

bool isLooped(set<int>* field, int sz, int index = 0, int parent = -1, bool* marked = nullptr)
{
	if (marked == nullptr)
	{
		marked = new bool[sz];
		memset(marked, 0, sz);
	}

	marked[index] = true;

	for (auto iter = field[index].begin(); iter != field[index].end(); ++iter)
	{
		if (!marked[*iter])
		{
			if (isLooped(field, sz, *iter, index, marked))
				return true;
		}
		else if (*iter != parent)
			return true;
	}
	return false;
}

void solve()
{
	int sz, edges;
	scanf("%d %d", &sz, &edges);

	auto field = new set<int>[sz];
	for (int i = 0; i < sz; i++)
		field[i] = *new set<int>();
	for (int i = 0; i < edges; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		field[a - 1].insert(b - 1);
		field[b - 1].insert(a - 1);
	}

	bool looped = isLooped(field, sz);
	bool connected = isConnected(field, sz);

	printf("%d\n", connected ? looped ? 1 : 2 : 0);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
