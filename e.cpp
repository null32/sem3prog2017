#include <cstdio>

bool* a;
int* b;

void solve()
{
	int f, s;
	scanf("%d %d", &f, &s);

	printf("%d\n", b[f] * b[s]);
}

int main()
{
	int K = 10000;
	a = new bool[K];
	for (int i = 0; i < K; i++)
		a[i] = 0;

	for (int i = 2; i < K; i++)
	{
		if (!a[i])
		{
			for (int j = i * i; j < K; j += i)
			{
				a[j] = 1;
			}
		}
	}

	b = new int[K];
	int count = 0;
	for (int i = 1; i < K; i++)
	{
		if (!a[i])
		{
			b[count] = i;
			count++;
		}
	}

	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
