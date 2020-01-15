#include <iostream>
using namespace std;

int main()
{
	double g = -9.8, xt;
	int x0, v0, t;
	cin >> x0 >> v0 >> t;
	//xt = x0 + v0 * t + g * t * t / 2;
	x0 = g * t * t / 2;
	v0 = 1/2 * g * t * t;
	//cout << xt << endl;
	cout << x0 << endl;
	cout << v0 << endl;
	return 0;
}
