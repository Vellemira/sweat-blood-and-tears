#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int b, i;
	double a, c;
	cin >> a >> b;
	c = a;
	if (b < 0)
	{
		for (i = -1; i > b; i--) c *= a;
		cout << 1 / c;
	}
	else
	{
		if (b > 0)
		{
			for (i = 1; i < b; i++)
				c *= a;
		}
		if (b == 0)
		{
			c = 1;
		}
		cout << c;
	}
}
