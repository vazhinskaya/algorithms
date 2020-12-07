#include <iostream>
#include <ctime>
using namespace std;
int main() {
	int *a;
	int n;
	n = pow(2, 8);
	a = new int[n];

	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}


	int t, m; 
	for (int i = 1; i < n; i++) {
		t = a[i]; 
		m = i - 1; 
		while (m >= 0 && a[m] > t) {
			a[m + 1] = a[m];
			a[m] = t;
			m--;
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