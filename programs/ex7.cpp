#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int vvod;
	cout << "Выберите способ параметров треугольника:" << "\n" << "Если даны стороны, введите 1. Если даны координаты, введите 2" << endl;
	cin >> vvod;
	if (vvod == 1)
	{
		double a, b, c, p, s;
		cout << "Введите стороны треугольника" << endl;
		cin >> a >> b >> c;
		if ((a + b > c) && (b + c > a) && (a + c > b))
		{
			p = (a + b + c) * 0.5;
			s = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "S=" << s;
		}
		else
			cout << "Error";
	}
	else
		if (vvod == 2)
	{
		int A, B, C, x1, x2, x3, y1, y2, y3, s2;
		cout << "Введите координаты точки А: ";
		cin >> x1 >> y1;
		cout << "Введите координаты точки B: ";
		cin >> x2 >> y2;
		cout << "Введите координаты точки C: ";
		cin >> x3 >> y3;

		A = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		B = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
		C = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if ((A + B <= C) || (A + C <= B) || (B + C <= A))
		{
			cout << "Треугольник не существует";
			return 0;
		}
		else
		{
			s2 = (A + B + C) / 2;
			s2 = sqrt(s2 * (s2 - A) * (s2 - B) * (s2 - C));
			cout << "S=" << s2;
		}


	}
	else
		cout << "Error";
}