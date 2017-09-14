#include <cstdio>
#include <algorithm>
#include <functional>

const int lim = 30;
using namespace std;

void solve(int eggs, int floors)
{
	/*
		eggs >
		tries v
	*/
	auto field = new int*[lim + 1];
	for (int i = 0; i <= lim; i++)
		field[i] = new int[eggs + 1];

	for (int i = 0; i <= eggs; i++)
		field[0][i] = 0;
	for (int i = 0; i <= lim; i++)
		field[i][0] = 0;

	int res = -1;

	for (int i = 1; i <= lim; i++)
	{
		for (int j = 1; j <= eggs; j++)
		{
			field[i][j] = 1 + field[i - 1][j] + field[i - 1][j - 1];
			if (field[i][j] >= floors)
			{
				res = i;
				break;
			}
		}
		if (res != -1)
			break;
	}

	printf("%d\n", res);
}

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
		solve(a, b);
}
