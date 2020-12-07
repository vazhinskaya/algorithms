d[0] = 1
int sum = 0;
for (int j = 0; j < N + 1; j++) {
	if (j < (K + 1)) {
		sum += d[j];
		d[j + 1] = sum;
	}
	else {
		sum += d[j];
		d[j + 1] = sum - d[j - K];
		}
}
cout << d[N];


