#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	double a, b, c, x, x1, x2;
	cin >> a >> b >> c;


	if (a == 0) 
	{
		if (b != 0)
			cout << "x=" << -c / b;
		else 
		{
			if (c == 0)
				cout << "Бесконечное множество решений";
			else
				cout << "Нет решения";
		}
	}
	else
	{
		x = b * b - 4 * a * c;
		if (x >= 0)
		{
			if (x == 0)
				cout << -b / (2 * a);
			else 
			{
				x1 = (-b + sqrt(x)) / (2 * a);
				x2 = (-b - sqrt(x)) / (2 * a);
				cout << x1 << endl;
				cout << x2;
			}
			
		}
		else {
			cout << "Нет корней";
		}
	}
	return 0;
}
