#include <cstdio>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(0));

	int max = 1000;

	auto crand = [max](){ return rand() % max; };

	int n = crand();
	int cost = crand();

	printf("%d %d\n", n, cost);
	for (int i = 0; i < n; i++)
		printf("%d ", crand());
}
