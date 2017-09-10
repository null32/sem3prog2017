#include <cstdio>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

void solve()
{
	char str[10];
	cin >> str;

	char res = 0;
	int i = 0;
	while (str[i] != 0)
	{
		res = max(str[i], res);
		i++;
	}

	printf("%c\n", res);
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		solve();
}
