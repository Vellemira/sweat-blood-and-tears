#include <iostream>
using namespace std;
void sort(int* arr, int i)
{
	for (int k = 0; k < i - 1; k++)
	{
		for (int j = 0; j < i - k - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}

}
int main()
{
	int l, k = 0;
	cin >> l;
	int* arr = new int[l];
	for (int f = 0; f < l; f++) {

		cin >> arr[f];
	}
	for (int i = 1; i <= l; i++)
	{
		sort(arr, i);
		if (i > 5) {

			k++;
		}
		for (int p = k; p < i; p++)
		{
			cout << arr[p] << " ";
		}
		cout << endl;
	}
	delete[] arr;
	return 0;
}