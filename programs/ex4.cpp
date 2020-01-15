#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b;
	c = a;
	a = b;
	b = c;
	cout << a << "\t" << b << endl;
	b = b + a;
	a = b - a;
	b = b - a;
	cout << a << "\t" << b << endl;
}