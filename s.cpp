#include <cstdio>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <set>

using namespace std;

int find(bool** field, int sz, int start, int finish, int ttl, set<int>* marked)
{
	#ifdef DEBUG
	printf("-> %d ", start + 1);
	#endif
	if (ttl < 0)
	{
		#ifdef DEBUG
		puts("<- ttl");
		#endif
		return 0;
	}
	if (start == finish && ttl >= 0)
	{
		#ifdef DEBUG
		puts("<- found");
		#endif
		return 1;
	}

	int res = 0;
	if (marked == nullptr)
		marked = new set<int>();

	auto me = marked->insert(start).first;
	for (int i = 0; i < sz; i++)
	{
		if (field[start][i] && marked->find(i) == marked->end())
		{
			res += find(field, sz, i, finish, ttl - 1, marked);
			#ifdef DEBUG
			printf("<- %d\n", start + 1);
			#endif
		}
	}
	marked->erase(me);

	return res;
}

void solve()
{
	int count, routes, start, finish, ttl;
	scanf("%d %d %d %d %d", &count, &routes, &start, &finish, &ttl);

	auto field = new bool*[count];
	for (int i = 0; i < count; i++)
	{
		field[i] = new bool[count];
		memset(field[i], false, count);
	}

	for (int i = 0; i < routes; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		field[a - 1][b - 1] = true;
	}

	int res = find(field, count, start - 1, finish - 1, ttl, nullptr);
	printf("%d\n", res);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
