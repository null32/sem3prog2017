#include <cstdio>
#include <algorithm>
#include <functional>
#include <climits>
#include <memory.h>
#include <malloc.h>

typedef long long ll;
using namespace std;

void solve()
{
	int sz;
	scanf("%d", &sz);
	sz++;

	auto dims = new ll[sz];
	for (int i = 0; i < sz; i++)
		scanf("%lld", &dims[i]);

	auto seqCost = new ll*[sz];
	for (int i = 0; i < sz; i++)
	{
		seqCost[i] = new ll[sz];
		memset(seqCost[i], 0, sz * sizeof(ll));
	}

	#ifdef DEBUG
	printf("seqCost:\n");
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - 1; j++)
			printf("%10lld ", seqCost[i][j]);
		printf("%10lld\n", seqCost[i][sz - 1]);
	}
	#endif

	for (int seqLen = 2; seqLen < sz; seqLen++)
	{
		for (int seqStart = 1; seqStart < sz - seqLen + 1; seqStart++)
		{
			int seqEnd = seqLen + seqStart - 1;
			seqCost[seqStart][seqEnd] = LLONG_MAX;
			for (int k = seqStart; k < seqEnd; k++)
			{
				ll cost = seqCost[seqStart][k] + seqCost[k + 1][seqEnd] +
					dims[seqStart - 1] * dims[k] * dims[seqEnd];
				if (cost < seqCost[seqStart][seqEnd])
					seqCost[seqStart][seqEnd] = cost;
			}
		}
	}

	#ifdef DEBUG
	printf("seqCost:\n");
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - 1; j++)
			printf("%10lld ", seqCost[i][j]);
		printf("%10lld\n", seqCost[i][sz - 1]);
	}
	#endif

	printf("%lld\n", seqCost[1][sz - 1]);

}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
