#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

void solve()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", __gcd(a, b));
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
