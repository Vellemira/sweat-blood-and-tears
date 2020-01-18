#include <iostream>
using namespace std;

void factorization(int n) {
	int num = 2; int flag = 0;
	while (n != 1) {
		while (n % num == 0) {
			flag += 1;
			//cout  << num<< " * ";
			n /= num;
		}
		if (flag == 1) { cout << num; }
		else {
			if (flag > 1) { cout << num << "^" << flag; }
		}
		num += 1;
		if (n != 1 && flag != 0) cout << "*";
		flag = 0;
	} cout << endl;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << " Введите натуральное число ---  ";
	cin >> n;
	if (n > 0)
		factorization(n); else cout << "Ошибка, Введите натуральное число " << endl;
	return 0;
}
