#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	double a = 0, b = 0;
	char sign='?';
	cout << "Введите выражение: ";
	cin >> a >> sign >> b;
	switch (sign) {
	case '*':
		cout << a * b << endl;
		break;
	case '/':
		if (b == 0)
			cout << "Ошибка. Деление на ноль невозможно." << endl;
		else
			cout << a / b << endl;
		break;
	case '+':
		cout << a + b << endl;
		break;
	case '-':
		cout << a - b << endl;
		break;
	default:
		cout << "Ошибка. Неверный формат ввода." << endl;
	}
	
	return 0;
}
