#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

void solve()
{
	int sz;
	scanf("%d", &sz);

	long long res;
	long long a;
	long long b;

	scanf("%lld", &a);
	scanf("%lld", &b);
	res = __gcd(a, b);
	for (int i = 2; i < sz; i++)
	{
		scanf("%lld", &a);
		res = __gcd(res, a);
	}

	printf("%lld\n", res);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
