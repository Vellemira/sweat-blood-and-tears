#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, x1, x2, d, y, x_max, x_min, x;

	bool flag = true;

	cin >> a >> b >> x1 >> x2 >> d;
	cout << " x" << "\t" << "  y" << endl;
	cout << "----------------" << endl;
	x = x1;
	x_max = 0;
	x_min = 0;

	for (int i = 0; i <= (x2-x1)/d; i++, x += d) 
	{

		if (x <= a) y = abs(x);
		else if ((a < x) && (x < b)) y = abs(x) + cos(x);
		else if (x >= b) y = tan(x);

		if (flag) 
		{
			x_max = y;
			x_min = y;
			flag = false;
		}
		else if (y > x_max) x_max = y;
		else if (y < x_min) x_min = y;

		cout << x << " \t " << y << endl;
	}
	cout << "----------------" << endl;
	cout << "max: " << x_max << "\t" << "min: " << x_min << endl;
	return 0;
}