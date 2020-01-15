#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	unsigned int n, k;
	int i = 0;
	k = 1;
	cout << "Введите целое число от 0 до 10^15: ";
	cin >> n;
	while (k <= n) 
	{
		k *= 2;
		i++;
	}
	cout << i;
	return 0;
}