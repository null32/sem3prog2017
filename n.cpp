#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);

		int count = 0;
		int temp;
		while (n > 0)
		{
			temp = n;
			while (temp > 0)
			{
				n -= temp % 10;
				temp /= 10;
			}
			count++;
		}
		printf("%d\n", count);
	}
}
