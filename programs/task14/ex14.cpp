#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int sum, l1, l2, r1, r2, x1, x2;
	cout << "Введите сумму чисел: " << endl;
	cin >> sum;
	cout << "Введите первый диапазон чисел: " << endl;
	cin >> l1 >> r1;
	cout << "Введите второй диапазон чисел: " << endl;
	cin >> l2 >> r2;
	for (int i = l1; i <= r1; i++)
	{
		for (int k = l2; k <= r2; k++)
		{
			if (i + k == sum)
			{
				cout << "x1 = " << i << endl;
				cout << "x2 = " << k << endl;
				return 0;
			}
		}
	}
	cout << -1;
}
