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
