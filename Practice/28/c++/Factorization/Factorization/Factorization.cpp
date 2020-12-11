#include<vector>
#include <iostream>
#include <algorithm>
#include<map>
void print_factorization(unsigned int n)
{
	std::map <unsigned int, unsigned int> slv;
	int div = 2;
	while (n > 1)
	{
		for (unsigned int i = 2; i <= n; i++)
		{
			if (!(n % i))
			{
				n /= i;

				slv[i] = slv.count(i) ? slv[i] + 1 : 1;
				break;
			}
		}
	}
	std::cout << "1";
	for (auto r : slv)
	{
		if (r.second > 1)
		{
			std::cout << "*" << r.first << "^" << r.second;
		}
		else
		{
			std::cout << "*" << r.first;
		}
	}
}
int main()
{
	unsigned int n;
	std::cin >> n;
	print_factorization(n);
}
