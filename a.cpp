#include <cstdio>
#include <algorithm>

using namespace std;

void solve()
{
	int w, h;
	scanf("%d %d", &h, &w);

	int** field = new int*[h];
	for (int i = 0; i < h; i++)
	{
		field[i] = new int[w];

		for (int j = 0; j < w; j++)
		{
			scanf("%d", &(field[i][j]));
		}
	}

	for (int i = h - 1; i >= 0; i--)
	{
		for (int j = w - 1; j >= 0; j--)
		{
			field[i][j] += max(i == h - 1 ? 0 : field[i + 1][j], j == w - 1 ? 0 : field[i][j + 1]);
		}

		#ifdef DEBUG
		for (int aa = 0; aa < h; aa++)
		{
			for (int ab = 0; ab < w; ab++)
				printf("%3d ", field[aa][ab]);
			printf("\n");
		}
		printf("\n");
		#endif
	}
	printf("%d\n", field[0][0]);
}

int main()
{
	auto t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
