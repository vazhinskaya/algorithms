#include <iostream>
#include <ctime>
using namespace std;

void fun(int a[], int n)
{
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int *c = new int[max + 1 - min];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i] - min] = c[a[i] - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			a[i] = j;
			c[j - min]--;
			i++;
		}
	}
}

int main() {
	int *a;
	int n = 100;
	int *a = new int[n];

	//a[0] = 1;

	//for (int i = 0; i < n; i++) {
	//	a[i] = a[i - 1] + 1;
	//}

	//for (int i = 0; i < n; i++) {
	//	if (i % 100 == 0)
	//		a[i] = rand();
	//}

	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand()%20 +1;
	};

	fun(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;
	delete[] a;
	system("pause");

	return 0;
}




