#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class sum
{
	public:
	sum(int ind, sum* b = nullptr) { index = ind; base = b; }
	~sum() { }
	int size() { return base == nullptr ? 0 : base->size() + 1; };
	sum* base;
	int index;
};

int main()
{
	int cost, n;
	scanf("%d %d", &n, &cost);
	auto money = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &money[i]);

	auto possible = *new vector<sum*>(cost + 1, nullptr);
	possible[0] = new sum(0);

	for (int i = 0; i < n; i++)
		for (int j = cost; j >= 0; j--)
			if (	possible[j] != nullptr && 
				money[i] + j <= cost && 
				(possible[money[i] + j] == nullptr ? true : possible[j]->size() + 1 < possible[money[i] + j]->size()))
			{
				possible[money[i] + j] = new sum(i, possible[j]);
			}

	if (possible[cost] != nullptr)
	{
		printf("%d\n", possible[cost]->size());
		auto v = *new vector<int>();
		sum* ptr = possible[cost];
		while (ptr != nullptr)
		{
			v.push_back(ptr->index);
			ptr = ptr->base;
		}
		sort(v.begin(), v.end());
		for (auto it = v.begin() + 1; it != v.end(); it++)
			printf("%d ", *it + 1);
	}
	else
		puts("-1");
}
