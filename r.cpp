#include <iostream>
#include <utility>
#include <memory.h>

using namespace std;

const int mod = 1000000007;

int dp[110][110] = {0};

int main()
{
	int n, sz;
	cin >> n >> sz;

	auto cooks = new pair<int, int>[sz];
	for (int i = 0; i < sz; i++)
		cin >> cooks[i].first >> cooks[i].second;

	for (int i = cooks[0].first; i <= cooks[0].second; i++)
		dp[0][i] = 1;

	for (int i = 1; i < sz; i++)
		for (int j = 0; j <= n; j++)
			for (int k = cooks[i].first; k <= cooks[i].second; k++)
				if (j - k >= 0)
				{
					dp[i][j] += dp[i - 1][j - k];
					if (dp[i][j] >= mod)
						dp[i][j] %= mod;
				}

	#ifdef DEBUG
	printf("dp:\n");
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j <= n; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	printf("cooks:\n");
	for (int i = 0; i < sz; i++)
		printf("(%d %d) ", cooks[i].first, cooks[i].second);
	printf("\n");
	#endif

	cout << dp[sz - 1][n] << endl;
}
