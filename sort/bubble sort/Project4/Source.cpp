#include <iostream>
using namespace std;
#include <ctime>
int main() {
	int *a;
	int n;
	n = pow(2, 8);
	a = new int[n];

	for (int i = 0; i < n; i++) {
		a[i] = rand()%20+1;
	}

	int t;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;
	delete[] a;
	system("pause");

	return 0;

}