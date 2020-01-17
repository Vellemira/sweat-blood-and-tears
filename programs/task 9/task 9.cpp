#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int a, b, c, i;
	c = 1;
	while (c == 1)
	{
		i = 0;
		a = rand() % 101;
		cout << "Добро пожаловать в игру Угадай число! Цель игры проста: нужно за 5 попыток угадать сгенерированное компьютером число от 0 до 100." << endl;
		cout << "Введите число:" << endl;
		while (i < 5)
		{
			cin >> b;
			if (b > a)
				cout << "Загаданное число меньше" << endl;
			else if (b < a)
			{
				cout << "Загаданное число больше" << endl;
			}
			else 
			{
				cout << "Поздравляем! Вы угадали!" << endl;
				break;
			}
			i++;
		}
		if (i == 5)
			cout << "Вы проиграли :( \n" << "Правильный ответ: " << a << endl;
		cout << "Желаете начать игру сначала? (Введите 1 для продолжения)" << endl;
		cin >> c;
	}
}
