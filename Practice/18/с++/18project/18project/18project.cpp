#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char word[20];
	char str[18] = { 'a','c','d','e','f','g','h','i','k','l','m','n','o','p','r','s','t','u' };
	const int k = 45;
	 int a[k];
	for (int i = 0; i < k; i++)
	{
		a[i] = 0;
	}
	while (true)
	{    
		for (int i = 0; i < 20; i++)
		{
			cin >> word[i];
			if (word[i] != ' ')
			{
				break;
			}
			else if (word[i]== str[i])
			{
				a[i]++;
				for (int i = 0; i <= 20; i++)
				{
					


				}
			}
		}
	}
}



