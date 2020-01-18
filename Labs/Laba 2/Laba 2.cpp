#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	double a, b, x1, x2, d, y, y_max, y_min, x;
	bool flag = true;

	cout << "Введите значение переменной а: ";
	cin >> a;
	cout << "Введите значение переменной b: ";
	cin >> b;
	cout << "Введите диапазон от: "; cin >> x1; cout << "до: "; cin >> x2;
	cout << "Ведите шаг: ";
	cin >> d;
	cout << " x" << "\t" << "  y" << endl;
	cout << "----------------" << endl;
	x = x1;
	y_min = 0;
	y_max = 0;

	for (int i = 0; i <= (x2-x1)/d; i++, x += d) 
	{

		if (x <= a) y = abs(x);
		else if ((a < x) && (x < b)) y = abs(x) + cos(x);
		else if (x >= b) y = tan(x);

		if (flag) 
		{
			y_min = y;
			y_max = y;
			flag = false;
		}
		else if (y < y_min) y_min = y;
		else if (y > y_max) y_max = y;

		cout << x << " \t " << y << endl;
	}
	cout << "----------------" << endl;
	cout << "минимум: " << y_min << "\t "<< "максимум: " << y_max << endl;
	return 0;
}