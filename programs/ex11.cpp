#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int a, fact;
	cout << "Введите целое положительное число: ";
	cin >> a;
	if (a == 0) 
		cout << "0!=1" << endl;
	else
		if (a > 0) 
		{
			fact = 1;
			for (int k = 1; k <= a; k++)
				fact *= k;
			cout << a << "! = " << fact << endl;
		}
		else 
			cout << "Введённое число не может быть отрицательным" << endl;
	return 0;
}