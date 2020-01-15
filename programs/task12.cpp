#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int a, i;
	cin >> a;
	if (a > 0)
	{
		if (a != 1)
		{
			for (i = 2; i < a; i++)
			{
				if (a % i == 0)
				{
					cout << "Составное";
					return 0;
				}
			}
			cout << "Простое";
		}
		else
		cout << "Не простое и не составное";
	}
	else
		cout << "Число не является положительным";
}
