#include <cstdio>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>

using namespace std;

void solve()
{
	char str[50];
	bool num[10];

	memset(num, false, 10);
	scanf("%s", str);

	int count = 10;
	for (int i = 0; i < strlen(str); i++)
	{
		if (num[str[i] - '0'] == false)
		{
			count--;
			num[str[i] - '0'] = true;
		}
	}

	printf("%d\n", count);
	for (int i = 0; i < 10; i++)
	{
		if (num[i] == false)
		{
			if (count != 1)
				printf("%d ", i);
			else
				printf("%d\n", i);
			count--;
		}
	}
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
